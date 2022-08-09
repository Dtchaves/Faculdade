/*Crie uma estrutura representando um aluno de uma disciplina. Essa estrutura
deve conter o número de matrícula do aluno, seu nome e as notas de três provas.
Agora, escreva um programa que leia os dados de cinco alunos e os armazena nessa
estrutura. Em seguida, exiba o nome e as notas do aluno que possui a maior média
geral dentre os cinco.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct alunodadiciplina {

	int matricula;
	char nome[50];
	float nota[3];

}aluno;

void main (){

	aluno lido[5];
	float media[5] = {0,0,0,0,0};
	float maiormedia = 3;
	int vaga = 0;
	int i,j; //leitores

	for(i = 0; i < 5; i++) {

		scanf("%i",&lido[i].matricula);
		setbuf(stdin,NULL);
		fgets(lido[i].nome,sizeof lido[i].nome,stdin);
		lido[i].nome[strlen(lido[i].nome) - 1] = '\0';

			for (j = 0; j<3; j++) {
				scanf("%f",&lido[i].nota[j]);
				media[i] += lido[i].nota[j];
			} 

		media[i] /= 3;
	}

	for (i = 0; i<5; i++){
		if(media[i] > maiormedia) {
			maiormedia = media[i];
			vaga = i;
		}
	}

	printf("%s com a media de %f",lido[vaga].nome,maiormedia);
}











