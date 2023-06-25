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
void saveToFile(struct book *libr, int ilosc);
int fileData(struct book *libr, int ilosc);

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
        printf("5 - zapisz do pliku biblioteka.txt\n");
        printf("6 - pobierz dane z pliku\n");
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
                case 5: saveToFile(library, ilosc);             break;
                case 6: ilosc=fileData(library, ilosc);         break;
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

void saveToFile(struct book *libr, int ilosc)
{
    FILE *fptr;
    fptr=fopen("biblioteka.txt", "a");

    //sprawdzam, czy powiodlo sie otwarcie pliku
    if(fptr!=NULL)
    {
        //Autor, tytul, rok wydania, ilosc stron
        for(int i=0;i<ilosc;i++)
        {
            fprintf(fptr, "%s|", libr[i].author);
            fprintf(fptr, "%s|", libr[i].title);
            fprintf(fptr, "%d|", libr[i].year);
            fprintf(fptr, "%d\n", libr[i].size);
        }
        printf("Zapisano do pliku\n");
    }
    else
    {
        printf("Blad otwarcia pliku\n");
    }
    fclose(fptr);
    
}

int fileData(struct book *libr, int ilosc)
{
    char fileName[21], line[50];
    FILE *fptr;
    //printf("podaj nazwe[max 20 znakow] pliku (dane zapisane od pierwszej lini w formacie autor|tytul|rokWydania|iloscStron): ");
    //scanf("%[^\n]%*c", fileName);
    //fptr=fopen(fileName, "r");
    fptr=fopen("biblioteka.txt", "r");
    if(ilosc==20) 
    {
        printf("Za duzo ksiazek w bazie");
        return ilosc;
    }
    else
    {
        while(fscanf(fptr, "%s", line)==1)
        {
            char *token=strtok(line, "|");
            for(int i=0; i<4, token!=NULL; i++)
            {
                int temp;
                switch(i)
                {
                    case 0: strcpy(libr[ilosc].author, token); break;
                    case 1: strcpy(libr[ilosc].title, token); break;
                    case 2: 
                        temp=atoi(token);
                        libr[ilosc].year=temp; 
                    break;
                    case 3: 
                        temp=atoi(token);
                        libr[ilosc].size=temp; 
                    break;
                }
                token=strtok(NULL, "|");
            }
            ilosc++;
        }
    }
    fclose(fptr);
    printf("Dodano dane z pliku biblioteka.txt");
    return ilosc;

}