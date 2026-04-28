#ifndef QUEUE_H
#define QUEUE_H

//* Veri Modelleri

typedef struct QueueNode
{
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *head;
    QueueNode *tail;
} Queue;

//* Fonksiyon İmzaları

Queue* queueCreate();

#endif