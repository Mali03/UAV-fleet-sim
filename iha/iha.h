#ifndef IHA_H
#define IHA_H

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

typedef struct Iha {
    int id;
    char name[50];
    float fuel; // 0-100 aralığında (%)
    float x, y; // konum (varsayılan = 0.0f)
    IhaStatus status; // varsayılan = BOSTA
    MissionType currentMission; // varsayılan = KESIF
} Iha;

//* Fonksiyon İmzaları

Iha *ihaCreate(int id, char *name, float fuel);
void ihaPrint(Iha *iha);
void ihaUpdateFuel(Iha *iha, float amount); // amount + ise artır - ise azalt (miktara ekleme yapar)
void ihaSetStatus(Iha *iha, IhaStatus status);
int ihaIsAvailable(Iha *iha); // görev atanabilir mi?
void ihaFree(Iha *iha);

#endif