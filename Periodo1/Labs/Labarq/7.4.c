#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa {
char nome[50];
int idade;
char telefone[20];
}pessoa;

void ler_arq(pessoa *p, int *tam, FILE *arquivo){

*tam = fread(p,sizeof(pessoa),100,arquivo);


}

void ler(pessoa *p){
	scanf("%s",p->nome);
	scanf("%d",&p->idade);
	scanf("%s",p->telefone);
	getchar();
}

void inserir(pessoa *p){
	ler(p);
	printf("Registro %s %d %s inserido\n",p->nome,p->idade,p->telefone);
}

void alterar(pessoa *p,int tam){
	pessoa novo_reg;
	ler(&novo_reg);
	int contador = 0;

	for (int j = 0; j <= tam;j++){
		if(!strcmp(novo_reg.nome,p[j].nome)){
			p[j] = novo_reg;
			contador++;
			break;
		}
	}
	if(contador){
		printf("Registro %s %d %s alterado\n",novo_reg.nome,novo_reg.idade,novo_reg.telefone);
	}
		else 
			printf("Registro %s invalido\n",novo_reg.nome);
}

void excluir(pessoa *p,int *tam){
	char novo_nome[50];
		scanf("%s",novo_nome);
		getchar();
	
	pessoa antigo_reg;
	int contador = 0,i,j;

	for ( j = 0; j <= *tam;j++){
		if(!strcmp(novo_nome,p[j].nome)){
			antigo_reg = p[j];

			for(i = j;i<*tam;i++){
				p[i] = p[i+1];
			}

			contador++;
			*tam -= 1;
			break;
		}
	}
	if(contador){
		printf("Registro %s %d %s excluido\n",antigo_reg.nome,antigo_reg.idade,antigo_reg.telefone);
	}
		else 
			printf("Registro %s invalido\n",novo_nome);
}

void exibir(pessoa *p,int tam){
	char novo_nome[50];
		scanf("%s",novo_nome);
		getchar();

	int j,contador = 0;
	

	for (j = 0; j <= tam;j++){
		if(!strcmp(novo_nome,p[j].nome)){
			contador++;
			break;
		}
	}
	if(contador){
		printf("Registro %s %d %s exibido\n",p[j].nome,p[j].idade,p[j].telefone);
	}
		else 
			printf("Registro %s invalido\n",novo_nome);
}

int main()
{
int i = 0;

char arqstr[50];
	scanf("%s",arqstr);
	getchar();

FILE *arquivo_entrada;
	arquivo_entrada = fopen(arqstr,"rb");

pessoa entrada[100];
	ler_arq(entrada, &i,arquivo_entrada);


char fazer[10];


while(scanf("%s",fazer) != EOF){

	getchar();

	if (!strcmp("Inserir",fazer)){
		if(i<100){
			inserir(&entrada[i]);
			i++;
		}
			else{
				printf("Espaco insuficiente\n");
			}
	}

	if (!strcmp("Alterar",fazer)){
		alterar(entrada,i);
	}

	if (!strcmp("Excluir",fazer)){
		excluir(entrada,&i);
	}
	
	if (!strcmp("Exibir",fazer)){
		exibir(entrada,i);
	}

}

fclose(arquivo_entrada);
return 0;
}