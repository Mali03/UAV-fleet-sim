#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

Node *createNode(Iha *iha)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->iha = iha;
    new->next = NULL;
    return new;
}

Node *addHead(Node *head, Iha *iha)
{
    Node *yeni = (struct Node *)malloc(sizeof(Node));
    if (!yeni)
    {
        printf("Bellek hatasi\n");
        return head;
    }

    yeni->iha = iha;
    yeni->next = head;

    return yeni;
}

Node *addTail(Node *head, Iha *iha)
{
    Node *yeni = (struct Node *)malloc(sizeof(Node));
    if (!yeni)
    {
        printf("Bellek hatasi\n");
        return head;
    }

    yeni->iha = iha;
    yeni->next = NULL;

    if (head == NULL)
        return yeni;

    Node *temp = head;

    while (temp->next)
        temp = temp->next;

    temp->next = yeni;

    return head;
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
        printf("latitude: %d longitude: %d\n", temp2->iha->lat, temp2->iha->lon);
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

Node *removeByValue(Node *head, Iha *iha)
{
    if (!head)
        return NULL;

    if (head->iha->lon == iha->lat && head->iha->lon == iha->lon)
        return removeHead(head);

    Node *temp = head;

    while (temp->next && (temp->next->iha->lat != iha->lat || temp->next->iha->lon != iha->lon))
        temp = temp->next;

    if (temp->next)
    {
        Node *sil = temp->next;
        temp->next = sil->next;
        free(sil);
    }

    return head;
}