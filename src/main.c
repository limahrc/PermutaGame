#include "caixa.h"

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

  exibeCaixa(S);
  return 0;
}
