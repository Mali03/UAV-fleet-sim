#ifndef HASH_MAP_H
#define HASH_MAP_H

#include "../iha/iha.h"

//? max iha idsi [0,100]
#define TABLE_SIZE 100

//* Fonksiyon İmzaları

typedef struct HashNode
{
    int key; // Iha id
    Iha *value;
    struct HashNode *next;
} HashNode;

typedef struct
{
    HashNode *buckets[TABLE_SIZE];
} HashMap;

//* Fonksiyon İmzaları

HashMap *hashMapCreate();
void hashMapPut(HashMap *map, int key, Iha *value);
Iha *hashMapGet(HashMap *map, int key);
void hashMapRemove(HashMap *map, int key);
void hashMapFree(HashMap *map);

#endif