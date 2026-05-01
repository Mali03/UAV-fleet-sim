#ifndef LINKED_LIST_H
#define LINKED_LIST_H

//* Veri Modeli

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

//* Fonksiyon imzaları

Node* createNode(int x, int y);
Node* addHead(Node* head, int x, int y);
Node* addTail(Node* head, int x, int y);
Node* locate(Node* head, int x, int y);

void printList(Node* head);
int count(Node* head);

Node* removeHead(Node* head);
Node* removeTail(Node* head);
Node* removeByValue(Node* head, int x, int y);

#endif