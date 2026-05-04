#ifndef QUEUE_H
#define QUEUE_H

#include "../waypoint/waypoint.h"

//* Veri Modelleri

// İHA görev tipleri
typedef enum
{
    KESIF = 0,
    KARGO = 1,
    ACIL = 2
} MissionType;

// Görev structı
typedef struct
{
    int id;
    MissionType type;
    int ihaId;
} Mission;

typedef struct MissionQueueNode
{
    Mission *value;
    struct MissionQueueNode *next;
} MissionQueueNode;

typedef struct MissionQueue
{
    MissionQueueNode *head;
    MissionQueueNode *tail;
} MissionQueue;

//* Fonksiyon İmzaları

MissionQueue *missionQueueCreate();
void missionQueueEnqueue(MissionQueue *q, Mission *mission);
Mission *missionQueueDequeue(MissionQueue *q);
Mission *missionQueuePeek(MissionQueue *q);
int missionQueueIsEmpty(MissionQueue *q);
void missionQueueFree(MissionQueue *q);

#endif