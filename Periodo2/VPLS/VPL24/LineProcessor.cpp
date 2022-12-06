#include <regex>
#include <math.h>
#include <string>
#include <vector>
#include <sstream>

#include "LineProcessor.hpp"

using namespace std;

void LinePrinter::processaLinha(const std::string &str) {
  std::cout << str << std::endl;
}

bool ContadorPopRural::linhaValida(const std::string &str) const {
  // Neste exemplo usaremos expressoes regulares para verificar se uma linha
  // eh valida ou nao.
  //
  // Esta expressao regular eh formada por cinco partes. Cada uma dessas
  // partes eh um dos tres tipos de padrao regular abaixo:
  //
  // \\w+ eh qualquer palavra com um ou mais digitos, letras e sublinhas (_)
  // \\s* eh qualquer sequencia de zero ou mais espacos (inclui tab)
  // \\d+ eh qualquer sequencia de um ou mais digitos
  std::regex regularExpr("\\w+\\s*\\d+\\s*\\d+");

  // A funcao regex_match vai retornar verdadeiro se a string str casa-se com
  // a expressao regular que acabamos de criar:
  return std::regex_match(str, regularExpr);
}

void ContadorPopRural::processaLinha(const std::string &str) {
  //
  // Em geral eh mais facil ler dados de uma string se a string eh transformada
  // em um objeto do tipo stringstream:
  std::stringstream ss(str);
  //
  // Iremos ler os dados da string nestas tres variaveis abaixo:
  std::string nomePais;
  unsigned populacao, percUrbana;
  //
  // Como sabemos que a linha contem string int int, podemos fazer a leitura
  // facilmente usando o operador de streaming:
  ss >> nomePais >> populacao >> percUrbana;
  //
  // Note que precisamos arredondar o valor que serah impresso. O arredondamento
  // serah feito via a funcao floor. Ou seja, decimais serao sempre
  // arredondados para baixo:
  unsigned popRural = floor(populacao - (populacao * (percUrbana/100.0)));
  //
  // Uma vez encontrados os valores que precisam ser impressos, seguimos o
  // modelo do enunciado do exercicio:
  std::cout << popRural << " pessoas vivem no campo no " << nomePais <<
    std::endl;
}

bool ContadorNumNaturais::linhaValida(const std::string &str) const {
  stringstream aux(str);
  char individual;
  while(aux>>individual){
    if((individual != ' ') && (individual < '0' || individual >'9')) return false;
  }

  return true;
}

void ContadorNumNaturais::processaLinha(const std::string &str) {
  if(linhaValida(str)){
    stringstream aux(str);
    int total = 0;
    int individual;
    while(aux>>individual) 
    {
      total += individual;
    }  std::cout << total << std::endl;
  }
}

bool LeitorDeFutebol::linhaValida(const std::string &str) const {
  std::regex regularExpr("\\s*\\w+\\s*\\d+\\s*\\w+\\s*\\d+\\s*");
  return std::regex_match(str, regularExpr);
}

void LeitorDeFutebol::processaLinha(const std::string &str) {
  if(linhaValida(str)){
    stringstream aux(str);
    int aux1,aux2;
    string keep1,keep2;
    aux>>keep1;
    aux>>aux1;
    aux>>keep2;
    aux>>aux2;
    if(aux1==aux2)std::cout <<"Empate"<< std::endl;
    else if(aux1>aux2)std::cout << "Vencedor: "<<keep1 << std::endl;
         else std::cout << "Vencedor: "<<keep2 << std::endl;
  }
}

void ContadorDePalavras::processaLinha(const std::string &str) {
  int total = 0;
   stringstream aux(str);
   string save;
   while(aux>>save) total++;
  std::cout <<total<< std::endl;
}

bool InversorDeFrases::linhaValida(const std::string &str) const {
  stringstream aux(str);
  char individual;
  while(aux>>individual){
    if((individual != ' ') && (individual <'a' || individual > 'z')&& (individual <'A' || individual > 'Z')) return false;
  }
  return true;
}

void InversorDeFrases::processaLinha(const std::string &str) {
   stringstream aux(str);
   string save;
   vector<string> x;
   while(aux>>save) x.push_back(save);
  for(int i = (x.size()-1);i>=0;i--) std::cout <<x[i]<< std::endl;
}

bool EscritorDeDatas::linhaValida(const std::string &str) const {
  std::string dateFormat = "\\s*\\d\\d?/\\d\\d?/\\d{4}";
  regex aux(dateFormat);
  // TODO: Implemente este metodo
  // Note que você pode usar uma expressao regular como:
  // "\\s*\\d\\d?/\\d\\d?/\\d{4}" para saber se a linha eh valida:
  return std::regex_match(str, aux);
}

void EscritorDeDatas::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  // Lembre-se que as iniciais dos meses sao:
  // "Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out",
  // "Nov", e "Dez".
    stringstream aux(str);
    string aux1;
    vector<int> x;
    while(getline(aux,aux1,'/')) x.push_back(stoi(aux1));
  vector<string> saida = {"Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out","Nov","Dez"};
  std::cout << saida[x[1] - 1]<< std::endl;
}