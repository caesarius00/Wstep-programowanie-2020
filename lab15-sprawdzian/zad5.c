#include <stdio.h>
#include <string.h>

typedef struct
{
    char nazwa[50];
    float cena;
    int ilosc;
}MagazynType;

void add(MagazynType *magazyn, int *ile)
{
    if(*ile<50)
    {
        printf("Podaj nazwe: ");
        scanf("%s", magazyn[*ile].nazwa);
        printf("Podaj ilosc: ");
        scanf("%d", &magazyn[*ile].ilosc);
        (*ile)++;
        printf("-----dodano-----");
    }else printf("Brak miejsca");
}
void count(MagazynType *magazyn, int *ile)
{
    if(ile>0)
    {
        int count=0;
        char nazwa[50];
        printf("Podaj nazwe szukanego produktu: ");
        scanf("%s", nazwa);
        for(int i=0; i<*ile; i++)
        {
            if(strcmp(nazwa, magazyn[i].nazwa)==0) count+=magazyn[i].ilosc;
        }
        printf("Dostepnosc w magazynie: %d", count);

    }else printf("Brak rzeczy w magazynie\n");
}

void save(MagazynType *magazyn, int *ile)
{
    FILE *text=fopen("mazazyn.txt", "a+");
    FILE *binary=fopen("magazyn.bin", "ab+");
    int choice=1;
    while(choice)
    {
        printf("1 - zapisz\n2 - pobierz dane\n0 - wroc\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            for(int i=0; i<*ile; i++)
            {
                fprintf(text, "%s %d\n", magazyn[i].nazwa, magazyn[i].ilosc);
                fwrite(&magazyn, sizeof(MagazynType), 2, binary);
            }
            break;
            case 2:
            for(int i=0; i<)
        }
    }

    fclose(text);
    fclose(binary);
}

int main()
{
    MagazynType magazyn[50];
    int choice=1, ile=0;
    while(choice)
    {
        fflush(stdin);
        printf("\n1 - dodaj towar\n2 - zlicz ilosc\n3 - zapis i odczyt tekstowo i binarnie stanu magazynu\n0 - wyjscie\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: add(magazyn, &ile);
                break;
            case 2: count(magazyn, &ile);
                break;
            case 3: save(magazyn, &ile);
                break;
        }
    }
    return 0;
}