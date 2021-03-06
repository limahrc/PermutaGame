#ifndef _CAIXA_H_
#define _CAIXA_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct no Bola;
typedef struct cabeca Caixa;

struct cabeca {
  int bolas;
  Bola *primeira, *ultima;
  Caixa *ant, *prox;
};

struct no {
  char letra;
  char *cor;
  Bola *prox;
};


/* Cabeçalhos das funções: */

Bola* novaBola(char cor[], char letra);

Caixa* novaCaixa(int nBolas);

void insereNaCaixa(Caixa* caixa, Bola* bola);

void exibeCaixa(Caixa* caixa);

void imprimeCx(Caixa *caixa);

void imprimeCxant(Caixa *caixa);

Caixa *ligaCaixa(Caixa* C1, Caixa* nova);

#endif
