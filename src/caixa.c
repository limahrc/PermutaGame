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

void imprimeCx(Caixa *caixa){
  Bola *aux=caixa->primeira;
  while(aux!=NULL){
    print(aux->cor); printf(" %c ", aux->letra);
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

void ligaCaixa(Caixa** C1, Caixa* nova){
  if(caixaVazia(*C1)) *C1 = nova;
  else if((*C1)->bolas > nova->bolas){
    nova->prox = *C1;
    (*C1)->ant = nova;
    *C1 = nova;
  }
  else{
    Caixa* aux = *C1;
    while (aux->prox != NULL) {
      if(aux->prox->bolas > nova->bolas){
        nova->prox = aux->prox;
        nova->prox->ant = nova;
        nova->ant = aux;
      }
      aux = aux->prox;
    }
    aux->prox = nova;
  }
}
