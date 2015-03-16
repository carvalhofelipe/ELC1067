#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void le_alunos(int* matriculas, char nomes[][50], int* n){
	int mat;
	char c;
	char nome[50];
	int i;
	int linha;
	FILE* f = fopen("alunos.txt", "r");
	linha = 0;
	while(feof(f) == 0){
		if(fscanf(f, "%d", &mat) <= 0)
		break;
		i = 0;
		c = fgetc(f);
			while(c != '\n' && feof(f) == 0){
			nome[i] = c;
			c = fgetc(f);
			i++;
        		}
		nome[i] = '\0';
		matriculas[linha] = mat;
		strcpy(nomes[linha], nome);
		linha++;
		}
	*n = linha;
	fclose(f);
}

void le_notas (float* medias) {
	int i=0, mat;
	float nota1, nota2;
	FILE* f = fopen("notas.txt", "r");
	while(feof(f) == 0){
		if(fscanf(f, "%d %f %f\n", &mat, &nota1, &nota2) <= 0)
        	break;
		medias[i] = (nota1 + nota2)/2;
		i++;
	}
	fclose(f);
}

void busca_aluno (char* nome, char nomes[][50], int n, float* medias){
	int i;
	for (i=0; i<n; i++){
		if (strstr(nomes[i], nome)!=NULL) {
		printf ("%f %s\n", medias[i], nomes[i]);
		}
	}
}

int main(int argc, char** argv){
	char* nome;
	int matriculas[50];
        char nomes[50][50];
        int n;
	float medias[50];
	if(argc > 1){
		strcpy(nome, argv[1]);
        }
        printf("%s\n", nome);
        le_alunos(matriculas, nomes, &n);	
        le_notas(medias);			
        busca_aluno(nome, nomes, n, medias);	
}
