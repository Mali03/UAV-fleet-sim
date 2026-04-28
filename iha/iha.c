#include "iha.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//* Fonksiyon gerçekleştirmeleri

Iha *ihaCreate(int id, char *name, float fuel)
{
    Iha *newIha = (Iha *)malloc(sizeof(Iha));

    newIha->id = id;
    strcpy(newIha->name, name);
    newIha->fuel = fuel;
    newIha->x = 0.0f;
    newIha->y = 0.0f;
    newIha->status = BOSTA;
    newIha->currentMission = KESIF;

    return newIha;
}

void ihaPrint(Iha *iha)
{
    if (iha == NULL)
        return;

    printf("------ Iha Bilgileri: ------\n");
    printf("ID: %d\n", iha->id);
    printf("Isim: %s\n", iha->name);
    printf("Yakiti: %.1f%%\n", iha->fuel);
    printf("Koordinatlar: x:%fy:%f\n\n", iha->x, iha->y);
}

void ihaUpdateFuel(Iha *iha, float amount)
{
    if (iha == NULL)
        return;

    iha->fuel += amount;

    if (iha->fuel < 0)
        iha->fuel = 0;
    else if (iha->fuel > 100)
        iha->fuel = 100;
}

void ihaSetStatus(Iha *iha, IhaStatus status)
{
    if (iha == NULL)
        return;

    iha->status = status;
}

int ihaIsAvailable(Iha *iha)
{
    if (iha == NULL)
        return 0;

    if (iha->status != BOSTA)
        return 0;

    if (iha->fuel < 20)
        return 0;

    return 1;
}

void ihaFree(Iha *iha)
{
    if (iha == NULL)
        return;

    free(iha);
}