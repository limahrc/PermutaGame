#ifndef _STR_H_
#define _STR_H_

#include "charll.h"

typedef Node* String;
typedef char* text;

/**
** Cria nova string a partir de texto estático
*/ String newString(text);


/**
** Concatena duas strings de forma simples
*/ void conc(String*, String);

/**
** Verifica se a string contém um caractere passado por parâmetro
*/ bool contains(char);

/**
** Imprime string
*/ void jumpLine(int);

/**
** Imprime string
*/ void print(String);

#endif
