#include <stdio.h>
#include <stdlib.h>
#include <str.h>


typedef struct cabeca caixa;
typedef struct no Bola;

struct no{
	String cor;
	char letra;
	Bola *prox;
};

struct cabeca{
	int nBolas;
	Bola *primeira;
	Bola *ultima;
	caixa *prox;
	caixa *ant;
};

void imprime(caixa *c){
	Bola *aux=c->primeira;
	while(aux!=NULL){
		print(aux->cor); printf(" %c ", aux->letra);
		aux=aux->prox;
	}
}

/* FUNCAO IMPRIME ANTERIOR ANTIGA

void imprimeCxant(caixa *cabeca){
	if(cabeca->ant!=NULL){
		imprimeCxant(cabeca->ant);
		Bola *aux=cabeca->primeira;
		while(aux!=NULL){
			print(aux->cor); printf(" %c ", aux->letra);
			aux=aux->prox;
		}
	}
	else{
		imprime(cabeca);
	}
}*/

void imprimeCxant(caixa *cabeca){
	if(cabeca->ant==NULL) imprime(cabeca);
	if(cabeca->ant!=NULL){
		imprimeCxant(cabeca->ant);
		imprime(cabeca);
	}
}

void troca(char *x, char *y){
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void permuta(caixa *cabeca, Bola *init){
	if(init==cabeca->ultima){
		if(cabeca->prox!=NULL)
			permuta(cabeca->prox,cabeca->prox->primeira);
		else{
			imprimeCxant(cabeca);
			printf("\n");
		}
	}
	else{
		Bola *aux=init;
		while(aux!=NULL){
			troca(&(init->letra), &(aux->letra));
			permuta(cabeca,init->prox);
			troca(&(init->letra), &(aux->letra));
			aux=aux->prox;
		}
	}
}


int main(){
	int qtd_Bolas;

	Bola *b1=(Bola *) malloc (sizeof(Bola));
	b1->letra='A';

	Bola *b2=(Bola *) malloc (sizeof(Bola));
	b2->letra='B';

	b1->cor = b2->cor = newString("Azul");

	b1->prox=b2;
	b2->prox=NULL;

	caixa *c1= (caixa*) malloc (sizeof(caixa));
	c1->nBolas=2;
	c1->primeira=b1;
	c1->ultima=b2;
	c1->ant=NULL;


	Bola *b11=(Bola *) malloc (sizeof(Bola));
	b11->letra='C';

	Bola *b22=(Bola *) malloc (sizeof(Bola));
	b22->letra='D';

	Bola *b33=(Bola *) malloc (sizeof(Bola));
	b33->letra='E';

	b11->cor = b22->cor = b33->cor = newString("Rosa");

	b11->prox=b22;
	b22->prox=b33;
	b33->prox=NULL;

	caixa *c2= (caixa*) malloc (sizeof(caixa));
	c2->nBolas=3;
	c2->primeira=b11;
	c2->ultima=b33;
	c2->prox=NULL;
	c2->ant=c1;

	c1->prox=c2;
	caixa *color=c1;
	Bola *aux=c1->primeira;

	permuta(c1,aux);

	return 0;
}

