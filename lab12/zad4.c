#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char title[21];
    char author[21];
    int year;
    int size;
}bookType;

int main()
{
    bookType book, book2;
    int count=0;
    char line[50];
    FILE *fileBin, *fileLibrary;
    fileBin=fopen("biblioteka.bin", "wb");
    fileLibrary=fopen("biblioteka.txt", "r");

    //pobieranie linii, zapisywanie danych w zmiennej book, a nastepnie zapisywanie binarne
    while(fscanf(fileLibrary, "%s", line)==1)
    {
        char *token=strtok(line, "|");
        for(int i=0; i<4, token!=NULL; i++)
        {
            int temp;
            switch(i)
            {
                case 0: strcpy(book.author, token); break;
                case 1: strcpy(book.title, token); break;
                case 2: 
                    temp=atoi(token);
                    book.year=temp; 
                break;
                case 3: 
                    temp=atoi(token);
                    book.size=temp; 
                break;
            }
            token=strtok(NULL, "|");
        }
        fwrite(&book, sizeof(bookType), 1, fileBin);
        count++;
    }
    fclose(fileBin);
    fclose(fileLibrary);

    //sprawdzanie, czy dobrze zapisano
    FILE *binSec;
    binSec=fopen("biblioteka.bin", "rb");
    printf("Do pliku zapisano binarnie: \n");
    for(int i=0; i<count; i++)
    {
        fread(&book2, sizeof(bookType), 1, binSec);
        printf("%s %s %d %d\n", book2.author, book2.title, book2.year, book2.size);
    }
    fclose(binSec);
    return 0;
}