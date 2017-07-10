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

void exibeCaixa(Caixa* caixa) {
  if(caixaVazia(caixa)) printf("Caixa vazia.\n");
  else{
    int i = 1;
    Caixa* caux = caixa;
    while(caux != NULL){
      printf("\nCaixa C%i: contém as seguintes bolas:\n", i);
      Bola* aux = caux->primeira;
      while (aux!=NULL) {
        printf("%s %c\n", aux->cor, aux->letra);
        aux = aux->prox;
      }
      caux = caux->prox;
      i++;
    }
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

Caixa *ligaCaixa(Caixa* primeira, Caixa* nova) {
  if(primeira==NULL){
    nova->ant = nova->prox = NULL;
    return nova;
  }else {
    Caixa *ant = NULL;
    Caixa *aux = primeira;
    while (aux != NULL) {
      if (nova->bolas < aux->bolas) break;
      else{
        ant=aux;
        aux = aux->prox;
      }
    }
    if(ant!=NULL) ant->prox=nova;
    else primeira=nova;
    nova->ant=ant;
    nova->prox=aux;
    if(aux!=NULL) aux->ant=nova;

    return primeira;
  }
}
