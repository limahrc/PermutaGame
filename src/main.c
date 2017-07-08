#include "caixa.h"

int main(int argc, char const *argv[]) {
  Caixa* C1;
  Caixa* aux;
  int i, cxs, bol;
  char ltr;
  printf("Quantas caixas? "); scanf("%i", &cxs);
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
    }
    ligaCaixa(C1, aux);
  }
  exibeCaixa(C1);
  return 0;
}
