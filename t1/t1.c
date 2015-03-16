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

