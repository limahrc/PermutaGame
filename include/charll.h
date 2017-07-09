#ifndef _CHARLL_H_
#define _CHARLL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct no Node;

Node* newNode(char);

Node* getPrevious(Node*, Node*);

Node* getNext(Node*);

void setNextNode(Node** last, Node* next);

char getInfo(Node*);

void insertAtTop(Node**, char c);

void insertAtEnd(Node**, char c);

void insertFromVec(char[], Node**);

void walk(Node**);

#endif
