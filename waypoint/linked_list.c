#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

WaypointNode *wllCreateNode(Waypoint *waypoint)
{
    WaypointNode *new = (WaypointNode *)malloc(sizeof(WaypointNode));
    new->waypoint = waypoint;
    new->next = NULL;
    return new;
}

WaypointNode *wllAddHead(WaypointNode *head, Waypoint *waypoint)
{
    WaypointNode *yeni = (struct WaypointNode *)malloc(sizeof(WaypointNode));
    if (!yeni)
    {
        printf("Bellek hatasi\n");
        return head;
    }

    yeni->waypoint = waypoint;
    yeni->next = head;

    return yeni;
}

WaypointNode *wllAddTail(WaypointNode *head, Waypoint *waypoint)
{
    WaypointNode *yeni = (struct WaypointNode *)malloc(sizeof(WaypointNode));
    if (!yeni)
    {
        printf("Bellek hatasi\n");
        return head;
    }

    yeni->waypoint = waypoint;
    yeni->next = NULL;

    if (head == NULL)
        return yeni;

    WaypointNode *temp = head;

    while (temp->next)
        temp = temp->next;

    temp->next = yeni;

    return head;
}

void wllPrintList(WaypointNode *head)
{
    if (head == NULL)
    {
        printf("Listede eleman yok!");
        return;
    }
    WaypointNode *temp2 = head;
    while (temp2 != NULL)
    {
        printf("latitude: %d longitude: %d\n", temp2->waypoint->latitude, temp2->waypoint->longitude);
        temp2 = temp2->next;
    }
}

int wllCount(WaypointNode *head)
{
    int counter = 0;
    WaypointNode *temp = head;
    while (temp != NULL)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}

WaypointNode *wllRemoveHead(WaypointNode *head)
{

    if (!head)
        return NULL;

    WaypointNode *temp = head;

    head = head->next;

    free(temp);

    return head;
}

WaypointNode *wllRemoveTail(WaypointNode *head)
{
    if (!head)
        return NULL;

    if (!head->next)
    {
        free(head);
        return NULL;
    }

    WaypointNode *temp = head;

    while (temp->next->next)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;

    return head;
}

WaypointNode *wllRemoveById(WaypointNode *head, int id)
{
    if (!head)
        return NULL;

    if (head->waypoint->id == id)
        return wllRemoveHead(head);

    WaypointNode *temp = head;

    while (temp->next && temp->next->waypoint->id != id)
        temp = temp->next;

    if (temp->next)
    {
        WaypointNode *sil = temp->next;
        temp->next = sil->next;
        free(sil);
    }

    return head;
}