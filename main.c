#include <stdio.h>
#include <stdlib.h>

#include "iha/iha.h"
#include "hash_map/hash_map.h"
#include "queue/queue.h"
#include "bst/bst.h"
#include "waypoint/linked_list.h"

// TODO tüm ihaları yazdırma ekle

int main()
{
    int menu = 1, subMenu = 1;
    int choice, subChoice;
    int id, status;
    float fuel;
    char name[50];
    Iha *iha;
    HashMap *map = hashMapCreate();
    Bst *missionBst = bstCreate();
    Mission *mission;

    printf("\n==========================================================");
    printf("\nInsansiz Hava Araci Filo Yonetim ve Gorev Planlama Sistemi");
    printf("\n==========================================================\n");
    while (menu)
    {
        printf("\n1- IHA Islemleri\n");
        printf("2- Waypoint Islemleri\n");
        printf("3- Gorev Islemleri\n");
        printf("0- Cikis\n");
        printf("\nBir secim yapiniz: ");

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("\nYanlis secim yapildi! Tekrar deneyiniz.\n\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            subMenu = 1;
            while (subMenu)
            {
                printf("\n1- IHA Olustur\n");
                printf("2- IHA Yazdir\n");
                printf("3- IHA Yakit Guncelle\n");
                printf("4- IHA Durum Ayarla\n");
                printf("5- IHA Sil\n");
                printf("0- Geri don\n");

                printf("\nBir secim yapiniz: ");

                if (scanf("%d", &subChoice) != 1)
                {
                    while (getchar() != '\n')
                        ;
                    printf("\nYanlis secim yapildi! Tekrar deneyiniz.\n\n");
                    continue;
                }

                switch (subChoice)
                {
                case 1:
                    printf("\nLutfen olusturulacak IHA'nin ID'sini girin: ");
                    scanf("%d", &id);
                    printf("\nLutfen olusturulacak IHA'nin ismini giriniz: ");
                    scanf("%s", name);
                    printf("\nLutfen olusturulacak IHA'nin yakit doluluk oranini girin (0-100): ");
                    scanf("%f", &fuel);

                    iha = ihaCreate(id, name, fuel);
                    iha->missionQueue = missionQueueCreate();
                    hashMapPut(map, id, iha);

                    printf("IHA basariyla olusturuldu.\n");

                    break;
                case 2:
                    printf("\nLutfen IHA'nin ID'sini giriniz: ");
                    scanf("%d", &id);
                    iha = hashMapGet(map, id);

                    if (iha == NULL)
                    {
                        printf("IHA bulunamadi.\n");
                    }
                    else
                    {
                        ihaPrint(iha);
                    }
                    break;
                case 3:
                    printf("\nLutfen yakiti guncellenecek IHA'nin ID'sini giriniz: ");
                    scanf("%d", &id);
                    iha = hashMapGet(map, id);

                    if (iha == NULL)
                    {
                        printf("IHA bulunamadi.\n");
                    }
                    else
                    {
                        printf("Yeni yakit miktarini giriniz: ");
                        scanf("%f", &fuel);
                        ihaUpdateFuel(iha, fuel);
                        printf("[#%d] %s isimli IHA'nin yakit miktari %.2f olarak guncellendi.\n", id, iha->name, fuel);
                    }
                    break;

                case 4:
                    printf("\nLutfen durumu ayarlanacak IHA'nin ID'sini giriniz: ");
                    scanf("%d", &id);
                    iha = hashMapGet(map, id);

                    if (iha == NULL)
                    {
                        printf("IHA bulunamadi.\n");
                    }
                    else
                    {
                        printf("0- BOSTA\n1- GOREVDE\n2- ARIZALI\n3- YAKIT_DUSUK\n\n");
                        printf("Yeni durumu giriniz: ");
                        scanf("%d", &status);
                        ihaSetStatus(iha, (IhaStatus)status);
                        printf("IHA'nin durumu guncellendi.\n");
                    }
                    break;
                case 5:
                    printf("\nLutfen silinecek IHA'nin ID'sini giriniz: ");
                    scanf("%d", &id);
                    iha = hashMapGet(map, id);

                    if (iha == NULL)
                    {
                        printf("IHA bulunamadi.\n");
                    }
                    else
                    {
                        printf("[#%d] %s isimli IHA filodan kaldirildi.", id, iha->name);
                        ihaFree(iha);
                        hashMapRemove(map, id);
                    }
                    break;
                case 0:
                    subMenu = 0;
                    break;
                default:
                    printf("\nLutfen seceneklerden bir tanesini secin.\n");
                    break;
                }
            }
            break;

        case 2:
            printf("\nLutfen waypointleri duzenlenecek IHA'nin ID'sini giriniz: ");
            scanf("%d", &id);
            iha = hashMapGet(map, id);

            if (iha == NULL)
            {
                printf("IHA bulunamadi.\n");
                break;
            }

            subMenu = 1;
            while (subMenu)
            {
                printf("\n1- Waypoint Ekle\n");
                printf("2- Waypoint Sil\n");
                printf("3- Waypoint Listele\n");
                printf("4- Waypoint Sayisini Yazdir\n");
                printf("0- Geri don\n");

                printf("\nBir secim yapiniz: ");

                if (scanf("%d", &subChoice) != 1)
                {
                    while (getchar() != '\n')
                        ;
                    printf("\nYanlis secim yapildi! Tekrar deneyiniz.\n\n");
                    continue;
                }

                switch (subChoice)
                {
                case 1:
                {
                    Waypoint *wp = (Waypoint *)malloc(sizeof(Waypoint));
                    printf("Waypoint ID'sini giriniz: ");
                    scanf("%d", &wp->id);
                    printf("Latitude: ");
                    scanf("%f", &wp->latitude);
                    printf("Longitude: ");
                    scanf("%f", &wp->longitude);
                    iha->waypointList = wllAddTail(iha->waypointList, wp);
                    printf("Waypoint eklendi.\n");
                }

                break;
                case 2:
                    printf("Waypoint ID'sini giriniz: ");
                    scanf("%d", &id);
                    iha->waypointList = wllRemoveById(iha->waypointList, id);
                    printf("Waypoint listeden silindi.");
                    break;

                case 3:
                    wllPrintList(iha->waypointList);
                    break;

                case 4:
                    printf("Toplam waypoint sayisi: %d", wllCount(iha->waypointList));
                    break;

                case 0:
                    subMenu = 0;
                    break;

                default:
                    printf("\nLutfen seceneklerden bir tanesini secin.\n");
                    break;
                }
            }
            break;

        case 3:
            printf("\nLutfen gorevleri duzenlenecek IHA'nin ID'sini giriniz: ");
            scanf("%d", &id);
            iha = hashMapGet(map, id);

            if (iha == NULL)
            {
                printf("IHA bulunamadi.\n");
                break;
            }

            subMenu = 1;
            while (subMenu)
            {
                printf("\n1- Gorev Ekle\n");
                printf("2- Gorev Baslat\n");
                printf("3- Gorev Sorgula\n");
                printf("0- Geri don\n");

                printf("\nBir secim yapiniz: ");

                if (scanf("%d", &subChoice) != 1)
                {
                    while (getchar() != '\n')
                        ;
                    printf("\nYanlis secim yapildi! Tekrar deneyiniz.\n\n");
                    continue;
                }

                switch (subChoice)
                {
                case 1:
                    printf("Gorev ID'sini giriniz: ");
                    scanf("%d", &id);
                    printf("0- KESIF\n1- KARGO\n2- ACIL\n\n");
                    printf("Gorev tipini giriniz: ");
                    scanf("%d", &status);

                    mission = (Mission *)malloc(sizeof(Mission));
                    mission->id = id;
                    mission->type = (MissionType)status;
                    mission->ihaId = iha->id;

                    missionQueueEnqueue(iha->missionQueue, mission);
                    bstInsert(missionBst, mission->id, mission);

                    printf("Gorev eklendi.\n");
                    break;

                case 2:
                    mission = missionQueueDequeue(iha->missionQueue);
                    if (mission == NULL)
                    {
                        printf("Kuyrukta gorev yok.");
                        break;
                    }
                    ihaSetStatus(iha, GOREVDE);

                    printf("\nGorev Baslatildi!\n- Gorev ID: #%d\n- Gorev Turu: ", mission->id);

                    switch (mission->type)
                    {
                    case KESIF:
                        printf("KESIF");
                        break;
                    case KARGO:
                        printf("KARGO");
                        break;
                    case ACIL:
                        printf("ACIL");
                        break;
                    }

                    printf("\n- IHA ID: %d\n", mission->ihaId);
                    break;

                case 3:
                    printf("Gorev ID'sini giriniz: ");
                    scanf("%d", &id);

                    mission = bstSearch(missionBst, id);
                    if (mission == NULL)
                    {
                        printf("\nGorev bulunamadi.\n");
                        break;
                    }

                    printf("\nGorev bulundu! Gorev Bilgileri:\n- Gorev ID: #%d\n- Gorev Turu: ", mission->id);

                    switch (mission->type)
                    {
                    case KESIF:
                        printf("KESIF");
                        break;
                    case KARGO:
                        printf("KARGO");
                        break;
                    case ACIL:
                        printf("ACIL");
                        break;
                    }

                    printf("\n- IHA id: %d\n", mission->ihaId);
                    break;

                case 0:
                    subMenu = 0;
                    break;

                default:
                    printf("\nLutfen seceneklerden bir tanesini secin.\n");
                    break;
                }
            }

            break;

        case 0:
            printf("\nProgram sonlandirildi.");
            menu = 0;
            break;

        default:
            printf("\nLutfen seceneklerden bir tanesini secin.\n");
            break;
        }
    }

    return 0;
}