#include "../iha/iha.h"
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

//* Veri Modeli

typedef struct Node
{
    Iha *iha;
    struct Node *next;
} Node;

//* Fonksiyon imzaları

Node *createNode(Iha *iha);
Node *addHead(Node *head, Iha *iha);
Node *addTail(Node *head, Iha *iha);
void printList(Node *head);
int count(Node *head);
Node *removeHead(Node *head);
Node *removeTail(Node *head);
Node *removeByValue(Node *head, Iha *iha);

#endif