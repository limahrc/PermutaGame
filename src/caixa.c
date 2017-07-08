#include "caixa.h"
#include <stdbool.h>

Bola* novaBola(char cor[], char letra){
  Bola* nova = (Bola*) calloc(1, sizeof(Bola));
  nova->cor = newString(cor);
  nova->letra = letra;
  return nova;
}

Caixa* novaCaixa(int nBolas){
  Caixa* nova = (Caixa*) calloc(1, sizeof(Caixa));
  nova->bolas = nBolas;
  return nova;
}

bool caixaVazia(Caixa* caixa){
  if(caixa == NULL || (caixa->primeira == NULL && caixa->ultima == NULL))
  return true;
  else return false;
}

void insereNaCaixa(Caixa* caixa, Bola* bola){
  if(caixaVazia(caixa)) caixa->primeira = caixa->ultima = bola;
  else{
    caixa->ultima->prox = bola;
    caixa->ultima = caixa->ultima->prox;
  }
}

void ligaCaixa(Caixa* primeira, Caixa* nova) {
  Caixa* aux = primeira;
  if(caixaVazia(primeira)){
    primeira = nova;
    nova->ant = nova->prox = NULL;
  } else {
    while (aux != NULL) {
      if (aux->prox->bolas > aux->bolas) {
        nova->prox = aux->prox;
        nova->prox->ant = nova;
        nova->ant = aux;
        aux->prox = nova;
      }
      aux = aux->prox;
    }
  }
}

void exibeCaixa(Caixa* caixa) {
  if(caixaVazia(caixa)) printf("Caixa vazia.\n");
  else{
    int i = 1;
    Caixa* caux = caixa;
    while(caux != NULL){
      printf("\nCaixa C%i: contém as seguintes bolas:\n", i);
      Bola* aux = caux->primeira;
      while (aux!=NULL) {
        print(aux->cor); printf(" %c\n", aux->letra);
        aux = aux->prox;
      }
      caux = caux->prox;
      i++;
    }
  }
}
