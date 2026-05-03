#ifndef IHA_H
#define IHA_H

#include "../waypoint/waypoint.h"

//* Veri Modelleri

// İHA durumları
typedef enum
{
    BOSTA = 0,
    GOREVDE = 1,
    ARIZALI = 2,
    YAKIT_DUSUK = 3
} IhaStatus;

// İHA görev tipleri
typedef enum
{
    KESIF = 0,
    KARGO = 1,
    ACIL = 2
} MissionType;

typedef struct Iha
{
    int id;
    char name[50];
    float fuel;                 // 0-100 aralığında (%)
    float lat, lon;             // konum (varsayılan = 0.0f) (lat = latitude (enlem) - lon = longitude (boylam))
    IhaStatus status;           // varsayılan = BOSTA
    MissionType currentMission; // varsayılan = KESIF
    WaypointNode *waypointList;
} Iha;

//* Fonksiyon İmzaları

Iha *ihaCreate(int id, char *name, float fuel);
void ihaPrint(Iha *iha);
void ihaUpdateFuel(Iha *iha, float newFuel);
void ihaSetStatus(Iha *iha, IhaStatus status);
int ihaIsAvailable(Iha *iha); // görev atanabilir mi?
void ihaFree(Iha *iha);

#endif