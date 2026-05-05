#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

MissionQueue *missionQueueCreate()
{
    MissionQueue *newQueue = (MissionQueue *)malloc(sizeof(MissionQueue));
    newQueue->head = NULL;
    newQueue->tail = NULL;

    return newQueue;
}

void missionQueueEnqueue(MissionQueue *q, Mission *mission)
{
    MissionQueueNode *newNode = (MissionQueueNode *)malloc(sizeof(MissionQueueNode));
    newNode->value = mission;
    newNode->next = NULL;

    if (q->head == NULL) // listede eleman yoksa
    {
        q->head = newNode;
        q->tail = newNode;
    }
    else
    {
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

Mission *missionQueueDequeue(MissionQueue *q)
{
    if (q->head == NULL)
    {
        printf("Kuyruk bos.");
        return NULL;
    }
    else
    {
        Mission *value = q->head->value;
        MissionQueueNode *temp = q->head->next;
        free(q->head);
        q->head = temp;
        return value;
    }
}

Mission *missionQueuePeek(MissionQueue *q)
{
    if (q->head == NULL)
        return NULL;

    return q->head->value;
}

int missionQueueIsEmpty(MissionQueue *q)
{
    return q->head == NULL;
}

void missionQueueFree(MissionQueue *q)
{
    MissionQueueNode *temp;
    while (q->head != NULL)
    {
        temp = q->head;
        q->head = q->head->next;
        free(temp);
    }

    free(q);
}

void missionQueuePrint(MissionQueue *q)
{
    if (missionQueueIsEmpty(q))
    {
        printf("IHA'nin herhangi bir gorevi bulunmamaktadir.\n");
        return;
    }
    MissionQueueNode *temp = q->head;

    const char *types[] = {"KESIF", "KARGO", "ACIL"};

    while (temp != NULL)
    {
        printf("[%d] Gorev tipi: %s\n", temp->value->id, types[temp->value->type]);
        temp = temp->next;
    }
}