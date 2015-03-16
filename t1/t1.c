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
