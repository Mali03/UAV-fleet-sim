#include "hash_map.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//* Fonksiyon gerçekleştirmeleri

HashMap *hashMapCreate()
{
    HashMap *map = (HashMap *)malloc(sizeof(HashMap));

    for (int i = 0; i < TABLE_SIZE; i++)
        map->buckets[i] = NULL;

    return map;
}

void hashMapPut(HashMap *map, int key, Iha *value) // key->id tutar / value -> ihayı tutar
{
    if (map == NULL)
        return;

    int index = (key < 0 ? -key : key) % TABLE_SIZE;

    // aynı keye sahip varsa onun value'sini degistiriyo

    HashNode *current = map->buckets[index];
    while (current != NULL)
    {
        if (current->key == key)
        {
            current->value = value;
            return;
        }
        current = current->next;
    }

    // yoksa devam

    HashNode *node = (HashNode *)malloc(sizeof(HashNode));
    node->key = key;
    node->value = value;

    // başa ekleme -> O(1)
    node->next = map->buckets[index];
    map->buckets[index] = node;
}

Iha *hashMapGet(HashMap *map, int key)
{
    if (map == NULL)
        return NULL;

    int index = key % TABLE_SIZE;

    HashNode *current = map->buckets[index];
    while (current != NULL)
    {
        if (current->key == key)
        {
            return current->value;
        }
        current = current->next;
    }

    return NULL;
}

void hashMapRemove(HashMap *map, int key)
{
    if (map == NULL)
        return;

    int index = key % TABLE_SIZE;

    HashNode *current = map->buckets[index];
    HashNode *prev = NULL;

    while (current != NULL)
    {
        if (current->key == key)
        {
            if (prev == NULL) // liste başında ise
                map->buckets[index] = current->next;
            else
                prev->next = current->next;

            free(current);
            return;
        }

        prev = current;
        current = current->next;
    }
}

void hashMapFree(HashMap *map)
{
    if (map == NULL)
        return;

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        HashNode *current = map->buckets[i];

        while (current != NULL)
        {
            HashNode *temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(map);
}