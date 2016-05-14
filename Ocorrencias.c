#include "Cabecalhos.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void imprime (Tree* noh)
{
	if (noh != NULL) {
		printf("%c\t%d\n", noh->c, noh->peso);
		imprime(noh->dir);
	}
}

Tree* insere (Tree* noh, char c, int peso)
{
    Tree* novo = (Tree *) malloc(sizeof(Tree));
    Tree* ant = NULL;
    Tree* p = noh;

    novo->c = c;
	novo->peso = peso;

    while (p != NULL && p->peso >= novo->peso) {
        ant = p;
        p = p->dir;
    }

    if (ant == NULL) {
        novo->dir = noh;
        noh = novo;
    }
    else {
        novo->dir = ant->dir;
        ant->dir = novo;
    }
    
    return noh;
}

void ocorrencias (void)
{
	Tree* noh = NULL;
	
	int vetor[256];
	char frase[10000];
	printf("Digite uma frase: ");
	gets(frase);
	fflush(stdin);
	printf("\n");
	
	int i;
	for (i = 0; i < 256; i++)
		vetor[i] = 0;
	
	for (i = 0; i < strlen(frase); i++)
		vetor[frase[i]]++;
	
	for (i = 0; i < 256; i++)
		if (vetor[i] != 0)
			noh = insere(noh, i, vetor[i]);

	imprime(noh);
}

