#include "caixa.h"
#include <string.h>
#include <stdbool.h>

Bola* novaBola(char cor[], char letra){
  Bola* nova = (Bola*) calloc(1, sizeof(Bola));
  nova->cor = (char*) calloc(strlen(cor), sizeof(char));
  nova->cor = cor;
  nova->letra = letra;
  return nova;
}

Caixa* novaCaixa(int nBolas){
  Caixa* nova = (Caixa*) calloc(1, sizeof(Caixa));
  nova->bolas = nBolas;
  return nova;
}

bool caixaVazia(Caixa* caixa){
  if(caixa == NULL || (caixa->primeira == NULL && caixa->ultima == NULL)) //nao entendi esse "ou"
  return true;
  else return false;
}

void insereNaCaixa(Caixa* caixa, Bola* bola){
  if(caixaVazia(caixa)) caixa->primeira = caixa->ultima = bola;
  else{
    caixa->ultima->prox = bola;
    caixa->ultima = caixa->ultima->prox; //caixa->ultima->prox poderia ser modificada para bola
  }
}

void imprimeCx(Caixa *caixa){
  Bola *aux=caixa->primeira;
  while(aux!=NULL){
    printf("%s %c ", aux->cor, aux->letra);
    aux=aux->prox;
  }
}

void imprimeCxant(Caixa *caixa){
  if(caixa->ant==NULL) imprimeCx(caixa);
  if(caixa->ant!=NULL){
    imprimeCxant(caixa->ant);
    imprimeCx(caixa);
  }
}

Caixa* ligaCaixa(Caixa* primeira, Caixa* nova) {
  if(primeira == NULL){
    nova->ant = nova->prox = NULL;
    return nova;
  } else {
    Caixa *aux = primeira;
    while (aux->prox != NULL) {
      if (nova->bolas < aux->bolas) break;
      else aux = aux->prox;
    }
    if(aux->ant != NULL) aux->ant->prox=nova;
    else primeira = nova;
    nova->ant = aux->ant;
    nova->prox = aux;
    if(aux != NULL) aux->ant=nova;

    return primeira;
  }
}
