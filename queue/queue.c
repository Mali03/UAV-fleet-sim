#include "queue.h"

Queue *queueCreate()
{
    Queue *newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue->head = NULL;
    newQueue->tail = NULL;

    return newQueue;
}

void queueEnqueue(Queue *q, Iha *iha)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->value = iha;
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

Iha *queueDequeue(Queue *q)
{
    if (q->head == NULL)
    {
        printf("Kuyruk bos.");
    }
    else
    {
        Iha *value = q->head->value;
        QueueNode *temp = q->head->next;
        free(q->head);
        q->head = temp;
        return value;
    }
}

Iha *queuePeek(Queue *q)
{
    if (q->head == NULL)
        return NULL;

    return q->head->value;
}

int queueIsEmpty(Queue *q) {
    return q->head == NULL;
}

void queueFree(Queue *q) {
    QueueNode *temp;
    while (q->head != NULL) {
        temp = q->head;
        q->head = q->head->next;
        free(temp);
    }

    free(q);
}