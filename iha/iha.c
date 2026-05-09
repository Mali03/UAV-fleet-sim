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
    newIha->lat = 0.0f;
    newIha->lon = 0.0f;
    newIha->status = BOSTA;
    newIha->waypointList = NULL;

    return newIha;
}

void ihaPrint(Iha *iha)
{
    const char *statuses[]= {"BOSTA", "GOREVDE", "ARIZALI", "YAKIT_DUSUK"};
    if (iha == NULL)
        return;

    printf("------ Iha Bilgileri: ------\n");
    printf("ID: %d\n", iha->id);
    printf("Isim: %s\n", iha->name);
    printf("Yakiti: %%%.1f\n", iha->fuel);
    printf("Durum: %s\n", statuses[iha->status] );
    printf("Koordinatlar: lat:%f lon:%f\n\n", iha->lat, iha->lon);
}

void ihaUpdateFuel(Iha *iha, float newFuel)
{
    if (iha == NULL)
        return;

    if (newFuel < 0)
        iha->fuel = 0;
    else if (newFuel > 100)
        iha->fuel = 100;
    else
        iha->fuel = newFuel;
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
