#ifndef QUEUE_H
#define QUEUE_H

//* Veri Modelleri

typedef struct QueueNode
{
    Iha *value;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue
{
    QueueNode *head;
    QueueNode *tail;
} Queue;

//* Fonksiyon İmzaları

Queue *queueCreate();
void queueEnqueue(Queue *q, Iha *iha);
Iha *queueDequeue(Queue *q);
Iha *queuePeek(Queue *q);
int queueIsEmpty(Queue *q);
void queueFree(Queue *q);

#endif