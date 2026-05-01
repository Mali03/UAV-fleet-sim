#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

Node *createNode(int x, int y)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->x = x;
    new->y = y;
    new->next = NULL;
    return new;
}

Node *addHead(Node *head, int x, int y)
{
    Node *yeni = (struct Node *)malloc(sizeof(Node));
    if (!yeni)
    {
        printf("Bellek hatasi\n");
        return head;
    }

    yeni->x = x;
    yeni->y = y;
    yeni->next = head;

    return yeni;
}

Node *addTail(Node *head, int x, int y)
{

    Node *yeni = (struct Node *)malloc(sizeof(Node));
    if (!yeni)
    {
        printf("Bellek hatasi\n");
        return head;
    }

    yeni->x = x;
    yeni->y = y;
    yeni->next = NULL;

    if (head == NULL)
        return yeni;

    Node *temp = head;

    while (temp->next)
        temp = temp->next;

    temp->next = yeni;

    return head;
}

Node *locate(Node *head, int x, int y)
{
    while (head)
    {
        if (head->x == x && head->y == y)
        {
            printf("Deger bulundu!\n");
            return head;
        }
        head = head->next;
    }
    printf("Deger bulunmadi\n");
    return NULL;
}

void printList(Node *head)
{
    if (head == NULL)
    {
        printf("Listede eleman yok!");
        return;
    }
    const Node *temp2 = head;
    while (temp2 != NULL)
    {
        printf("x: %d y: %d\n", temp2->x, temp2->y);
        temp2 = temp2->next;
    }
}

int count(Node *head)
{
    int counter = 0;
    const Node *temp = head;
    while (temp != NULL)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}

Node *removeHead(Node *head)
{

    if (!head)
        return NULL;

    Node *temp = head;

    head = head->next;

    free(temp);

    return head;
}

Node *removeTail(Node *head)
{
    if (!head)
        return NULL;

    if (!head->next)
    {
        free(head);
        return NULL;
    }

    Node *temp = head;

    while (temp->next->next)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;

    return head;
}

Node *removeByValue(Node *head, int x, int y)
{
    if (!head)
        return NULL;

    if (head->x == x && head->y == y)
        return removeHead(head);

    Node *temp = head;

    while (temp->next && temp->next->x != x && temp->next->y)
        temp = temp->next;

    if (temp->next)
    {
        Node *sil = temp->next;
        temp->next = sil->next;
        free(sil);
    }

    return head;
}