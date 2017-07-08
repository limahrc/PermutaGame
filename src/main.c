#include "caixa.h"

void troca(char *x, char *y){
  char temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void permuta(Caixa *caixa, Bola *init){
  if(init==caixa->ultima){
    if(caixa->prox!=NULL)
      permuta(caixa->prox,caixa->prox->primeira);
    else{
      imprimeCxant(caixa);
      printf("\n");
    }
  }
  else{
    Bola *aux=init;
    while(aux!=NULL){
      troca(&(init->letra), &(aux->letra));
      permuta(caixa,init->prox);
      troca(&(init->letra), &(aux->letra));
      aux=aux->prox;
    }
  }
}

int main(int argc, char const *argv[]) {
  Caixa* C1 = NULL;
  Caixa* aux = NULL;
  int i, cxs, bol;
  char ltr;
  /*printf("Quantas caixas? "); scanf("%i", &cxs);
  for (i=0; i<cxs; i++) {
    printf("Caixa C%i: \nQuantas bolas? ", i+1);
    scanf("%i", &bol);
    aux = novaCaixa(bol);
    char cor[20];
    printf("Qual a cor das bolas? ");
    setbuf(stdin, NULL);
    scanf("%s", cor);
    for (i=0; i<bol; i++){
      printf("Digite a letra da %iª bola: ", i+1);
      ltr = getchar(); getchar();
      insereNaCaixa(aux, novaBola(cor, ltr));
      exibeCaixa(aux);
    }
    ligaCaixa2(&C1, aux);
  }*/

  C1 = novaCaixa(3);
  insereNaCaixa(C1, novaBola("Verde", 'J'));
  insereNaCaixa(C1, novaBola("Verde", 'G'));

  aux = novaCaixa(1);
  insereNaCaixa(aux, novaBola("Azul", 'U'));
  insereNaCaixa(aux, novaBola("Azul", 'R'));

  Caixa *C2 = novaCaixa(4);
  insereNaCaixa(C2, novaBola("Laranja", 'B'));
  insereNaCaixa(C2, novaBola("Laranja", 'Y'));

  ligaCaixa(&C1, C2);
  ligaCaixa(&C1, aux);


  exibeCaixa(C1);
  return 0;
}
