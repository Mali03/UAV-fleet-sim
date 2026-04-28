#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

//* Fonksiyon gerçekleştirmeleri

Bst *bstCreate()
{
    Bst *newBst = (Bst *)malloc(sizeof(Bst));
    newBst->root = NULL;
    return newBst;
}

void bstInsert(Bst *bst, int key, Iha *value)
{
    BstNode *newNode = (BstNode *)malloc(sizeof(BstNode));
    newNode->key = key;
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    if (bst->root == NULL)
    {
        bst->root = newNode;
        return;
    }

    BstNode *current = bst->root;

    while (1)
    {
        if (key < current->key)
        {
            if (current->left == NULL)
            {
                current->left = newNode;
                return;
            }
            current = current->left;
        }
        else if (key > current->key)
        {
            if (current->right == NULL)
            {
                current->right = newNode;
                return;
            }

            current = current->right;
        }
        else
        {                           // key == current->key
            current->value = value; // sadece Iha *value güncellensin
            free(newNode);          // yeniye gerek yok
            return;
        }
    }
}

Iha *bstSearch(Bst *bst, int key)
{
    BstNode *current = bst->root;

    if (current == NULL)
        return NULL;

    while (1)
    {
        if (key < current->key)
        {
            if (current->left == NULL)
            {
                return NULL;
            }
            current = current->left;
        }
        else if (key > current->key)
        {
            if (current->right == NULL)
            {
                return NULL;
            }
            current = current->right;
        }
        else
        {
            return current->value;
        }
    }
}

Iha *bstDelete(Bst *bst, int key)
{
    BstNode *current = bst->root;

    if (current == NULL)
        return NULL;

    BstNode *parent = NULL;
    Iha *dondurulecek = NULL;

    while (1)
    {
        if (key < current->key)
        {
            if (current->left == NULL)
            {
                return NULL;
            }
            parent = current;
            current = current->left;
        }
        else if (key > current->key)
        {
            if (current->right == NULL)
            {
                return NULL;
            }
            parent = current;
            current = current->right;
        }
        else
        {
            // tam anlamadım sonra bakcam
            if (current->left == NULL && current->right == NULL)
            {
                dondurulecek = current->value;

                if (parent == NULL)
                    bst->root = NULL;
                else if (key > parent->key)
                    parent->right = NULL;
                else
                    parent->left = NULL;

                free(current);
                return dondurulecek;
            }

            else if (current->left != NULL && current->right != NULL)
            {
                BstNode *successorParent = current;
                BstNode *successor = current->right;

                while (successor->left != NULL)
                {
                    successorParent = successor;
                    successor = successor->left;
                }

                current->key = successor->key;
                current->value = successor->value;

                if (successorParent == current)
                    successorParent->right = successor->right;
                else
                    successorParent->left = successor->right;

                dondurulecek = successor->value;
                free(successor);
                return dondurulecek;
            }
            else
            {
                dondurulecek = current->value;
                BstNode *child = (current->left != NULL) ? current->left : current->right;

                if (parent == NULL)
                    bst->root = child;
                else if (key > parent->key)
                    parent->right = child;
                else
                    parent->left = child;

                free(current);
                return dondurulecek;
            }
        }
    }
}

// Yardımcı fonksiyon (dışarıya açık değil)
void bstNodeFree(BstNode *node)
{
    if (node == NULL)
        return;

    bstNodeFree(node->left);
    bstNodeFree(node->right);
    free(node);
}

void bstFree(Bst *bst)
{
    if (bst == NULL || bst->root == NULL)
        return;

    bstNodeFree(bst->root);

    bst->root = NULL;
}

void bstNodePrintInOrder(BstNode *node)
{
    if (node != NULL)
    {
        bstNodePrintInOrder(node->left);
        printf("%d ", node->key);
        bstNodePrintInOrder(node->right);
    }
}

void bstPrintInOrder(Bst *bst)
{
    if (bst == NULL)
        return;

    bstNodePrintInOrder(bst->root);
}