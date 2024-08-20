#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

#define inf numeric_limits<double>::max()
#define epsilon 1e-10



/*
 * SIMPLEX
 * Nome: Diogo Tuler Chaves
 * Matrícula: 2022043663
 * 
 * Como rodar o código:
 * 1. Compile o código com um compilador C++:
 *    g++ -o simplex simplex.cpp
 * 
 * 2. Execute o programa:
 *    ./simplex arquivo.txt 
 */


/*______________________________________________________________DEFINIÇÔES DE VARIÁVEIS GLOBAIS______________________________________________________________*/
int m;
int n;

double **tableu_auxiliar;
double **tableu;
int * pivos;
int tamanho_pivos;
double* certificado;
int tamanho_certificado;
double* solucao;
int tamanho_solucao;


/*______________________________________________________________FUNÇÕES DE LEITURA E DE ESCRITA DOS DADOS______________________________________________________________*/

bool Leitura(string caminho_arquivo){

    ifstream arquivo(caminho_arquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return false; 
    }
    else{
        string linha;
        double elemento;


        getline(arquivo, linha);

        
        istringstream entradaMN(linha);

        /*Para mim faz mais sentido ser n váriáveis, logo preferi colocar dessa forma*/
        entradaMN>>m>>n;

        /*Alocação*/
        if(m<=n){
            tamanho_pivos = m;
            pivos = new int[m];
        }
        else{
            tamanho_pivos = n;
            pivos = new int[n];
        }

        tableu_auxiliar = new double*[m+1];
        for (int i = 0; i < (m+1); i++) {
            tableu_auxiliar[i] = new double[(m+n+m+1)];
        }

        tableu = new double*[m+1];
        for (int i = 0; i < (m+1); i++) {
            tableu[i] = new double[(m+n+1)];
        }

        /*Define soluções iniciais*/
        tableu_auxiliar[0][m+n+m] = 0.0;
        tableu[0][m+n] = 0.0;


        /*Define pivos iniciais*/
        for(int i = m+m+n-1;i >= m+n;i--){
            pivos[(i-n-m)] = i;
        }

        /*Define c*/
        for (int j = 0; j < m; j++) {
            tableu_auxiliar[0][j] = 0.0;
            tableu[0][j] = 0.0;
        }

        for (int j = m; j < m+n; j++) {
            tableu_auxiliar[0][j] = 0.0;
        }

        for (int j = m+n; j < m+m+n; j++) {
            tableu_auxiliar[0][j] = 1.0;
        }

        getline(arquivo, linha);
        istringstream entradaC(linha);

        for (int j = m; j < m+n; j++) {
            entradaC>>elemento;
            tableu[0][j] = -elemento;
        }

        /*Define A e B*/
        for(int i = 1; i < (m+1); i++){

            tableu[i][i-1] = 1;
            tableu_auxiliar[i][i-1] = 1.0;
            tableu_auxiliar[i][i+n+m-1] = 1.0;

            getline(arquivo, linha);
            stringstream entradaAB(linha); 

            double elemento;

            for (int j = 0; j < n+1; j++) {

                entradaAB>>elemento;

                if (j == n){
                    if(elemento < 0){
                        for (int k = 0; k < n+m+m; k++){
                            if(tableu[i][k]!= 0.0){tableu[i][k] = -tableu[i][k];}
                        }
                        for (int k = 0; k < n+m; k++){
                            if(tableu_auxiliar[i][k]!= 0.0){tableu_auxiliar[i][k] = -tableu_auxiliar[i][k];}
                        }
                         elemento = -elemento;
                    }
                    tableu_auxiliar[i][j+m+m] = elemento;
                    tableu[i][j+m] = elemento;
                }
                else{
                    tableu_auxiliar[i][j+m] = elemento;
                    tableu[i][j+m] = elemento;
                }

            }

        }


    }
    return true;
}

void Printa(bool printa_tableu_auxiliar, bool printa_tableu, bool printa_pivos){

    cout<<endl<<"_________________________________________________________________________________________________________________________________"<<endl;

    if(printa_tableu_auxiliar){
        cout<<endl<<"____________________Tableu Auxiliar____________________"<<endl<<endl;
        for (int i = 0; i < (m+1); i++) {
            for (int j = 0; j < (m+m+n+1); j++) {
                cout<<setw(6)<<tableu_auxiliar[i][j]<<" ";
                if(j == (m-1)){
                    cout<<setw(6)<<"| ";
                }
            }
            cout<<endl;
        }
    }
    cout<<endl;

    if(printa_tableu){
        cout<<"____________________Tableu____________________"<<endl<<endl;
        for (int i = 0; i < (m+1); i++) {
            for (int j = 0; j < (m+n+1); j++) {
                cout<<setw(6)<<tableu[i][j]<<" ";
                if(j == (m-1)){
                    cout<<setw(6)<<"| ";
                }
            }
            cout<<endl;
        }
    }
    cout<<endl;

    if(printa_pivos){
        cout<<"____________________Pivos____________________"<<endl<<endl;
        for(int i = 0;i < m;i++){
            cout<<pivos[i]<<"  ";
        }
    }
    cout<<endl<<endl;
}

/*______________________________________________________________FUNÇÕES PARA O SIMPLEX AUXILIAR______________________________________________________________*/

/*Checagem se existe valor negativo no C do auxiliar retorna -1 caso não tenha e, caso tenha, retorna a coluna do valor negativo*/
int ChecagemDoCAuxiliar(){
    for(int j = m; j<(n+m+m);j++){
        if(tableu_auxiliar[0][j]<0){
            return j;
        }
    }
    return -1;

}

/*Pega o certificado de inviabilidade*/
void CertificadoDeInviabilidade(){
    tamanho_certificado = m;
    certificado = new double[tamanho_certificado];

    for(int j=0;j<m;j++){
        certificado[j] = tableu_auxiliar[0][j];
    }
}


/*Resolve o simplex auxiliar*/
bool SimplexAuxiliar(){

    /*Ajusta a linha de custo inicial*/
    for(int i=1; i<m+1;i++){
        for(int j=0; j<m+n+m+1;j++){ 
            tableu_auxiliar[0][j] -= tableu_auxiliar[i][j];
        }
    }

    /*Checagem inicial de coeficientes negativos na função objetivo e valores negativos na coluna b*/
    int c_negativo = ChecagemDoCAuxiliar();

    /*Loop enquanto tiver coeficientes negativos na função objetivo e valores negativos na coluna b*/
    while(c_negativo != -1){



            double minimo = inf;
            int linha_minimo = -1;
            double valor;
            double conferir_epsilon;

            /*Acha qual dos elementos da coluna do c negativo que vai ser o novo pivo*/
            for(int i = 1; i<m+1;i++){

                /*Se o B for negativo invertemos sua linha*/
                if(tableu_auxiliar[i][m+n+m]<0){
                    for (int j = 0; j < n+m+m+1; j++){
                        if(tableu_auxiliar[i][j]!= 0){tableu_auxiliar[i][j] = -tableu_auxiliar[i][j];}
                    }
                }

                /*Conferimos para toda linha com valor maior que 0*/
                if(tableu_auxiliar[i][c_negativo]>0){
                    valor = tableu_auxiliar[i][m+m+n]/tableu_auxiliar[i][c_negativo];
                    if (valor < minimo){
                        minimo  = valor;
                        linha_minimo = i;
                    }
                
                }
            }

            /*Coloca o novo pivo da linha i na vaga i do vetor de pivos*/
            pivos[linha_minimo-1] = c_negativo;

            /*Fazemos o processo de pivoteamento, o valor nesse caso é o pivo*/
            valor = tableu_auxiliar[linha_minimo][c_negativo];


            /*Primeiro atualizamos a sua linha*/
            for(int j = 0;(j<m+n+m+1);j++){
                conferir_epsilon = tableu_auxiliar[linha_minimo][j]/valor;
                if(abs(conferir_epsilon)<epsilon){
                    tableu_auxiliar[linha_minimo][j] = 0.0;
                }
                else{
                    tableu_auxiliar[linha_minimo][j] = conferir_epsilon;
                }
            }

            /*Depois zeramos os elementos dessa coluna nas outras linhas*/
            for(int i = 0;(i<m+1);i++){
                if(i != linha_minimo){
                    valor = tableu_auxiliar[i][c_negativo];
                    for(int j = 0;(j<m+m+n+1);j++){
                        conferir_epsilon = tableu_auxiliar[i][j] - tableu_auxiliar[linha_minimo][j]*valor;
                        if(abs(conferir_epsilon)<epsilon){
                            tableu_auxiliar[i][j] = 0;
                        }
                        else{
                            tableu_auxiliar[i][j] = conferir_epsilon;
                        }
                    }
                }
            }
        
        
        c_negativo = ChecagemDoCAuxiliar();

    }

    if(tableu_auxiliar[0][m+n+m] == 0.0){
        return true;
    }

    else{
        CertificadoDeInviabilidade();
        return false;
    }

}
/*______________________________________________________________FUNÇÕES PARA O SIMPLEX NORMAL______________________________________________________________*/

/*Confere se um elemento esta no vetor de pivos*/
bool ElementoNoPivo(int elemento) {
    for (int i = 0; i < m; ++i) {
        if (pivos[i] == elemento) {
            return true;
        }
    }
    return false;
}

/*Tira os pivos que não são elementos no tableu normal*/
void ArrumaPivos(){

    for (int i = 0; i < tamanho_pivos; ++i) {
        if (pivos[i] > (m+n)) {
            // Encontrar o próximo menor elemento que não está no vetor
            for (int menor = m; menor < m+n; ++menor) {
                if (!ElementoNoPivo(menor)) {
                    pivos[i] = menor;
                    break;
                }
            }
        }
    }
}

/*Checagem se existe valor negativo no C do auxiliar retorna -1 caso não tenha e, caso tenha, retorna a coluna do valor negativo*/
int ChecagemDoC(){
    for(int j = m; j<(n+m);j++){
        if(tableu[0][j]<0){
            return j;
        }
    }
    return -1;

}

/*Pega o certificado de ilimitado*/
void CertificadoDeProblemaIlimitado(int coluna_negativa){
    tamanho_certificado = n;
    certificado = new double[tamanho_certificado];

    for(int j=0;j<n;j++){
        certificado[j] = 0.0;
    }

    certificado[coluna_negativa - m] = 1.0;


    for (int i = 1; i < tamanho_pivos + 1; ++i) {
        if( tableu[i][coluna_negativa] != 0){
            certificado[pivos[i - 1 ]-m] -= tableu[i][coluna_negativa];
        }
    }


}

/*Pega o certificado de otimalidade*/
void CertificadoDeOtimalidade(){
    tamanho_certificado = m;
    certificado = new double[tamanho_certificado];

    for(int j=0;j<m;j++){
        certificado[j] = tableu[0][j];
    }
}

/*Pega a solucao*/
void Solucao(){
    tamanho_solucao = n;
    solucao = new double[tamanho_solucao];

    for(int j=0;j<n;j++){
       solucao[j] = 0.0;
    }

    for (int i = 1; i < tamanho_pivos + 1; ++i) {
        solucao[pivos[i - 1 ]-m] = tableu[i][m+n];
    }

}


/* Resolve o simplex auxiliar */
bool Simplex() {
    ArrumaPivos();

    double conferir_epsilon;
    double valor;

    /* Ajusta a matriz tendo em vista os pivos achados no auxiliar */
    for (int p = 1; p < m + 1; p++) {
        valor = tableu[p][pivos[p - 1]];

        /* Se o pivo é 0 */
        if (valor == 0) {

            /*Começamos de m pois nao quereremos atrapalhar o que já está pivoteado*/
            for (int i = m ; i > 1; i--) {
                if (tableu[i][pivos[p - 1]] != 0) {
                    for (int j = 0; j < m + n + 1; j++) {
                        tableu[p][j] += tableu[i][j];
                    }
                    break;
                }
            }
            valor = tableu[p][pivos[p - 1]];
            if (valor == 0) {
                CertificadoDeProblemaIlimitado(tableu[p][pivos[p - 1]]);
                Solucao();
                return false;
            }
        }
        /* Primeiro atualizamos a sua linha */
        for (int j = 0; j < n + m + 1; j++) {
            conferir_epsilon = tableu[p][j] / valor;
            if (abs(conferir_epsilon) < epsilon) {
                tableu[p][j] = 0.0;
            } else {
                tableu[p][j] = conferir_epsilon;
            }
        }

        /* Depois zeramos os elementos dessa coluna nas outras linhas, inclusive do C */
        for (int i = 0; i < m + 1; i++) {
            if (i != p) {
                valor = tableu[i][pivos[p - 1]];
                for (int j = 0; j < m + n + 1; j++) {
                    conferir_epsilon = tableu[i][j] - tableu[p][j] * valor;
                    if (abs(conferir_epsilon) < epsilon) {
                        tableu[i][j] = 0;
                    } else {
                        tableu[i][j] = conferir_epsilon;
                    }
                }
            }
        }

    }

    /* Checagem inicial de coeficientes negativos na função objetivo e valores negativos na coluna b */
    int c_negativo = ChecagemDoC();


    /* Loop enquanto tiver coeficientes negativos na função objetivo e valores negativos na coluna b */
    while (c_negativo != -1) {

        double minimo = inf;
        int linha_minimo = -1;

        /* Acha qual dos elementos da coluna do c negativo que vai ser o novo pivo */
        for (int i = 1; i < m + 1; i++) {
            /* Conferimos para toda linha com valor maior que 0 */
            if (tableu[i][c_negativo] > 0) {
                valor = tableu[i][m + n] / tableu[i][c_negativo];
                if (valor < minimo) {
                    minimo  = valor;
                    linha_minimo = i;
                }
            }
        }

        if (linha_minimo == -1) {
            CertificadoDeProblemaIlimitado(c_negativo);
            Solucao();
            return false;
        }

        /* Coloca o novo pivo da linha i na vaga i do vetor de pivos */
        pivos[linha_minimo - 1] = c_negativo;

        /* Fazemos o processo de pivoteamento, o valor nesse caso é o pivo */
        valor = tableu[linha_minimo][c_negativo];

        /* Primeiro atualizamos a sua linha */
        for (int j = 0; j < n + m + 1; j++) {
            conferir_epsilon = tableu[linha_minimo][j] / valor;
            if (abs(conferir_epsilon) < epsilon) {
                tableu[linha_minimo][j] = 0.0;
            } else {
                tableu[linha_minimo][j] = conferir_epsilon;
            }
        }

        /* Depois zeramos os elementos dessa coluna nas outras linhas, inclusive do C */
        for (int i = 0; i < m + 1; i++) {
            if (i != linha_minimo) {
                valor = tableu[i][c_negativo];
                for (int j = 0; j < m + n + 1; j++) {
                    conferir_epsilon = tableu[i][j] - tableu[linha_minimo][j] * valor;
                    if (abs(conferir_epsilon) < epsilon) {
                        tableu[i][j] = 0;
                    } else {
                        tableu[i][j] = conferir_epsilon;
                    }
                }
            }
        }

        c_negativo = ChecagemDoC();
    }
    
    Solucao();
    CertificadoDeOtimalidade();
    return true;
}





/*______________________________________________________________FUNÇÃO MAIN______________________________________________________________*/

int main(int argc, char *argv[]) {



    if(Leitura(argv[1])){

        if(SimplexAuxiliar()){
            if(Simplex()){
                cout<<"otimo"<<endl;
                cout<<fixed << setprecision(3) << tableu[0][n+m]<< endl;
                    }
            else{
                cout<<"ilimitado"<<endl;
            }
            for(int j = 0;j<tamanho_solucao;j++){
                    cout << fixed << setprecision(3) << solucao[j] <<" ";
                }
                cout<<endl;
        }
        else{
            cout<<"inviavel"<<endl;
        }

        /*Printa o certificado*/
        for(int j = 0;j<tamanho_certificado;j++){
            cout << fixed << setprecision(3) << certificado[j] <<" ";
        }
        cout<<endl;


        /*Libera a memória alocada*/
        if (pivos) delete[] pivos;
        if (solucao) delete[] solucao;
        if (certificado) delete[] certificado;
        if (tableu_auxiliar) {
            for (int i = 0; i < (m + 1); i++) {
                if (tableu_auxiliar[i]) delete[] tableu_auxiliar[i];
            }
            delete[] tableu_auxiliar;
        }
    }

    return 0;
}