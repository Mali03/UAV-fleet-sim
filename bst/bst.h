#ifndef BST_H
#define BST_H

#include "../iha/iha.h"
#include "../queue/queue.h"

//* Veri Modelleri

typedef struct BstNode
{
    int key;
    Mission *value;
    struct BstNode *left;
    struct BstNode *right;
} BstNode;

typedef struct Bst
{
    BstNode *root;
} Bst;

//* Fonksiyon İmzaları

Bst *bstCreate();
void bstInsert(Bst *bst, int key, Mission *value);
Mission *bstSearch(Bst *bst, int key);
Mission *bstDelete(Bst *bst, int key);
void bstFree(Bst *bst);
void bstPrintInOrder(Bst *bst);

#endif