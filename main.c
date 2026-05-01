#include <stdio.h>
#include <stdlib.h>

#include "iha/iha.h"
#include "hash_map/hash_map.h"
#include "linked_list/linked_list.h"
#include "queue/queue.h"
#include "bst/bst.h"

int main()
{
    HashMap *map = hashMapCreate();
    
    if (hashMapGet(map, 10) != NULL)
    {
        printf("ID zaten kayitli!\n");
    }
    else
    {
        Iha *newIha = ihaCreate(10, "test", 100.0);
        hashMapPut(map, 10, newIha);
    }

    return 0;
}