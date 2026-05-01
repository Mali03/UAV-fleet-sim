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
    newNode->data = x;
    newNode->next = NULL;

    if (front == NULL) // listede eleman yoksa
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
    if (q->front == NULL)
    {
        printf("Kuyruk bos.");
    }
    else
    {
        QueueNode *temp = q->front->next;
        free(q->front);
        front = temp;
    }
}