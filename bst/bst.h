#ifndef BST_H
#define BST_H

#include "../iha/iha.h"

//* Veri Modelleri

typedef struct BstNode
{
    int key;
    Iha *value;
    struct BstNode *left;
    struct BstNode *right;
} BstNode;

typedef struct Bst
{
    BstNode *root;
} Bst;

//* Fonksiyon İmzaları

Bst *bstCreate();
void bstInsert(Bst *bst, int key, Iha *value);
Iha *bstSearch(Bst *bst, int key);
Iha *bstDelete(Bst *bst, int key);
void bstFree(Bst *bst);
void bstPrintInOrder(Bst *bst);

#endif