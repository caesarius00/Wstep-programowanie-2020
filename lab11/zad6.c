#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct book
{
    char title[21];
    char author[21];
    int year;
    int size;
};


int addBook(struct book *libr, int ilosc);
int rmBook(struct book *libr, int ilosc);
void searchYear(struct book *libr, int ilosc);
void searchAuthor(struct book *libr, int ilosc);

int main()
{
    struct book library[20];
    int ilosc=0;
    int task=10;
    char pozbywanie;
    while(task)
    {
        printf("\nM E N U\n");
        printf("1 - dodaj ksiazke\n");
        printf("2 - usun ksiazke\n");
        printf("3 - wyszukaj po roku\n");
        printf("4 - wyszukaj po autorze\n");
        printf("\n0 - wyjscie\n");
        scanf("%d", &task);
        scanf("%c", &pozbywanie); //fflush mi coś nie działa, może to wina linuxa
        //fflush(stdin);
        if(task)
        {
            switch(task)
            {
                case 1: ilosc=addBook(library, ilosc);          break;
                case 2: ilosc=rmBook(library, ilosc);           break;
                case 3: searchYear(library, ilosc);             break;
                case 4: searchAuthor(library, ilosc);           break;
            }
        }
        //system("clear");
    }
    return 0;
}

int addBook(struct book *libr, int ilosc)
{
    system("clear");
    if(ilosc==20) printf("Za duzo ksiazek w bazie");
    else
    {
        printf("Podaj tytul (nie wiecej niz 20 liter): ");
        scanf("%[^\n]%*c", libr[ilosc].title);
        printf("Podaj autora: ");
        scanf("%[^\n]%*c", libr[ilosc].author);
        printf("Podaj rok: wydania: ");
        scanf("%d", &(libr[ilosc].year));
        printf("Podaj ilosc stron: ");
        scanf("%d", &(libr[ilosc].size));
        ilosc++;
        return ilosc;
    }
    
}

int rmBook(struct book *libr, int ilosc)
{
    if(ilosc==0) printf("Brak ksiazek do usuniecia");
    else
    {
        char rmTitle[21];
        system("clear");
        printf("Podaj tytul ksiazki do usuniecia: ");
        scanf("%[^\n]%*c", rmTitle);
        for(int i=0; i<ilosc; i++)
        {
            if(!strcmp(rmTitle, libr[i].title))
            {
                libr[i]=libr[ilosc];
                strcpy(libr[ilosc].author, " ");
                libr[ilosc].size=0;
                strcpy(libr[ilosc].title, " ");
                libr[ilosc].year=0;
            }
        }

    }
    return ilosc;
}

void searchYear(struct book *libr, int ilosc)
{
    system("clear");
    int yearToFind, found=0;
    printf("Podaj rok, do wyszukania: ");
    scanf("%d", &yearToFind);
    for(int i=0; i<ilosc; i++)
    {
        if(libr[i].year==yearToFind)
        {
            found++;
            printf("%d. %s - \"%s\"\n", found, libr[i].author, libr[i].title);
        }
    }
    if(found) printf("Znaleziono %d wynik(ow)\n", found);
    else printf("Nie znaleziono ksiazek\n");
}

void searchAuthor(struct book *libr, int ilosc)
{
    char authorToFind[20], found=0;
    printf("Podaj autora (lub fragment) do znalezienia: ");
    scanf("%[^\n]%*c", authorToFind);
    for(int i=0; i<ilosc; i++)
    {
        if(strstr(libr[i].author, authorToFind))
        {
            found++;
            printf("%d. %s - \"%s\"\n", found, libr[i].author, libr[i].title);
        }
    }
    if(found) printf("Znaleziono %d wynik(ow)\n", found);
    else printf("Nie znaleziono wynikow\n");
}