#include "caixa.h"

void troca(char *x, char *y);
void permuta(Caixa *caixa, Bola *init);
int fatorial(int n);

int main() {
    char sair;

<<<<<<< HEAD
    Caixa *S = NULL, *aux = NULL;
    int i, j, possib=1, cxs=0, bol=0;
    char ltr, opt, cor[20];
=======
  Caixa *S = NULL, *aux = NULL;
  int i, j, possib=1, cxs, bol;
  char ltr, opt, sair, cor[20];
>>>>>>> e1b2c6b2ab7adf207d7638242045cfbc229c9fae

    do{

      system("clear");
      printf(":::::::::\tPERMUTA GAME\t:::::::::\n");
      printf("Quantas caixas serão? "); scanf("%i", &cxs);
      for (i=0; i<cxs; i++){
          printf("\nC%i: Qual será a cor das bolas nesta caixa? ", i+1);
          setbuf(stdin, NULL);
          scanf("%s", cor);

          printf("Quantas bolas serão? "); scanf("%i", &bol);
<<<<<<< HEAD
          possib*=fatorial(bol); //Obtendo número de possibilidades
=======
          possib=fatorial(bol)*possib; //Calcula o numero de possibilidades
>>>>>>> e1b2c6b2ab7adf207d7638242045cfbc229c9fae
          aux = novaCaixa(bol);

          for (j=0; j<bol; j++){
            printf("Digite a letra da %iª bola: ", j+1);
            getchar(); scanf("%c", &ltr);
            insereNaCaixa(aux, novaBola(cor, ltr));
          }

          S=ligaCaixa(S, aux); //Faz o encadeamento ordenado das caixas
      }
<<<<<<< HEAD
      printf("\nExistem %i possibilidades de resultados para este jogo.\n",
      possib);

      Caixa* aux2 = S;
      while (aux2!=NULL) {
        printf("%i ", aux2->bolas);
        aux2 = aux2->prox;
      }
=======
      printf("\nExistem %i possibilidades de resultados para este jogo.\n", possib);
>>>>>>> e1b2c6b2ab7adf207d7638242045cfbc229c9fae

      Caixa *aux2=S;
      printf("Sequencia definida: ");
      while(aux2!=NULL){
        printf("%s ",aux2->primeira->cor);
        aux2=aux2->prox;
      }
      
      do{
        printf("Deseja exibir todas as permutações? (s/n) "); getchar();
        scanf("%c", &opt);
        if(opt == 's' || opt == 'S'){
          printf("\n");
          permuta(S, S->primeira);
          break;
        }
        else if(opt == 'n' || opt == 'N') {
          printf("Ok.\n");
          break;
        }
        else printf("\nOpção inválida. Tente novamente. ");
    } while(opt);

    printf("\nDeseja jogar novamente? (s/n) "); getchar();
    scanf("%c", &sair);

    if(sair == 's' || sair == 'S'){
      S = aux = NULL;
       i = j = bol = cxs = 0;
       possib = 1;
    }
    else if(sair == 'n' || sair == 'N') break;
    else printf("\nOpção inválida. Tente novamente. ");
  } while(sair);
    printf("\n\nMuito obrigado!\nPrograma encerrado.\n");
  return 0;
}

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

int fatorial(int n){
  if(n==0 || n==1) return 1;
  else return n*fatorial(n-1);
}
