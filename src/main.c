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
  Caixa* S = NULL;
  Caixa* aux = NULL;
  int i, j, cxs, bol;
  char ltr, cor[20];
  system("clear");
  printf("Quantas caixas? "); scanf("%i", &cxs);
  for (i=0; i<cxs; i++){
      printf("\nC%i: Qual será a cor das bolas nesta caixa? ", i+1);
      setbuf(stdin, NULL);
      scanf("%s", cor);
      printf("Quantas bolas serão? "); scanf("%i", &bol);
      aux = novaCaixa(bol);
      for (j=0; j<bol; j++){
        printf("Digite a letra da %iª bola: ", j+1);
        getchar(); scanf("%c", &ltr);
        insereNaCaixa(aux, novaBola(cor, ltr));
      }
      ligaCaixa(&S, aux);
  }

<<<<<<< HEAD
  exibeCaixa(S);
=======
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
>>>>>>> 26016437354d8e86c2a1636c2b00dd3eb801e3c2
  return 0;
}
