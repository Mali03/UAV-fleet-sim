#include <stdio.h>
#include <stdlib.h>

#include "iha/iha.h"
#include "hash_map/hash_map.h"
#include "linked_list/linked_list.h"
#include "queue/queue.h"
#include "bst/bst.h"

int main()
{
    int choice, subChoice;
    int id, status;
    float fuel;
    char name[50];
    Iha *iha;
    HashMap *map = hashMapCreate();
    int subMenu = 1;

    printf("\n==========================================================");
    printf("\nInsansiz Hava Araci Filo Yonetim ve Gorev Planlama Sistemi");
    printf("\n==========================================================\n");
    while (1)
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
                    printf("\nLutfen bir IHA ismi giriniz: ");
                    scanf("%s", name);
                    printf("\nLutfen olusturulacak IHA'nin idsini girin: ");
                    scanf("%d", &id);
                    printf("\nLutfen olusturulacak IHA'nin yakit doluluk oranini girin (0-100): ");
                    scanf("%f", &fuel);

                    iha = ihaCreate(id, name, fuel);
                    hashMapPut(map, id, iha);

                    printf("IHA basariyla olusturuldu.\n");

                    break;
                case 2:
                    printf("\nLutfen IHA'nin idsini giriniz: ");
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
                    printf("\nLutfen yakiti guncellenecek IHA'nin idsini giriniz: ");
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
                    printf("\nLutfen durumu ayarlanacak IHA'nin idsini giriniz: ");
                    scanf("%d", &id);
                    iha = hashMapGet(map, id);

                    if (iha == NULL)
                    {
                        printf("IHA bulunamadi.\n");
                    }
                    else
                    {
                        printf("0- Bosta\n1- GOREVDE\n2- ARIZALI\n3- YAKIT_DUSUK\n");
                        printf("Yeni durumu giriniz: ");
                        scanf("%d", &status);
                        ihaSetStatus(iha, (IhaStatus)status);
                        printf("IHA'nin durumu guncellendi.\n");
                    }
                    break;
                case 5:
                    printf("\nLutfen silinecek IHA'nin idsini giriniz: ");
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
                    break;
                }
            }
            break;

        default:
            printf("\nLutfen seceneklerden bir tanesini secin.\n\n");
            break;
        }
    }

    return 0;
}