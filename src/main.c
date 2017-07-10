#include "caixa.h"

void troca(char *x, char *y);
void permuta(Caixa *caixa, Bola *init);
int fatorial(int n);

int main() {

  Caixa *S = NULL, *aux = NULL;
  int i, j, possib=1, cxs, bol, cont=0;// cont variavel auxiliar caso toas as caixas sejam nulas
  char ltr, opt, sair = 's', cor[20];

    do{
      system("clear");
      printf(":::::::::\tPERMUTA GAME\t:::::::::\n");
      printf("Quantas caixas serão? "); scanf("%i", &cxs);

      if(cxs > 0){ // caso em que o numero de caixas é maior do que 0
        for (i=0; i<cxs; i++){
            printf("\nC%i: Qual será a cor das bolas nesta caixa? ", i+1);
            setbuf(stdin, NULL);
            scanf("%s", cor);

            printf("Quantas bolas serão? "); scanf("%i", &bol);

            if( bol > 0){ // caso o numero de bolas seja maior que 0
              cont++;
              possib=fatorial(bol)*possib; //Calcula o numero de possibilidades
              aux = novaCaixa(bol);

              for (j=0; j<bol; j++){
                printf("Digite a letra da %iª bola: ", j+1);
                getchar(); scanf("%c", &ltr);
                insereNaCaixa(aux, novaBola(cor, ltr));
              }

              S = ligaCaixa(S, aux); //Faz o encadeamento ordenado das caixas
            }
            else printf("\nEsse número de bolas não é aceito.");
        }
        if(cont > 0){ // caso em que exista caixas e exista possibilidades para o jogo
          printf("\nExistem %i possibilidades de resultados para este jogo.\n", possib);

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
        }// fim do if(cont >0)
      }// fim do if(cxs > 0)
      else printf("\nEsse número de caixas não é aceito.");
      while(sair != 'n' || sair != 'N' || sair != 's' || sair != 'S'){
        printf("\nDeseja jogar novamente? (s/n) "); getchar();
        scanf("%c", &sair);
        if(sair != 'n' && sair != 'N' && sair != 's' && sair != 'S' ) printf("\nOpção inválida. Tente novamente. ");
        else break;
      }
      if(sair == 's' || sair == 'S'){ //Reinicia variaveis
			     S = aux = NULL;
		       i = j = cxs = bol = cont = 0;
			     possib = 1;
		  }
      else if(sair == 'n' || sair == 'N') break;
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
