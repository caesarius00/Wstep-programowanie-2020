#define MAX_BOOKS 50
#include <stdio.h>

typedef struct
{
    char title[21];
    char author[21];
    int year;
    int size;
}bookType;

void swapBook(bookType *lib, int higher, int smaller)
{
    bookType temp;
    temp=lib[higher];
    lib[higher]=lib[smaller];
    lib[smaller]=temp;
}

int main()
{
    //wczytywanie z pliku
    FILE *binLib;
    bookType library[MAX_BOOKS], book;
    int q=0;
    binLib=fopen("biblioteka.bin", "rb");
    while(fread(&book, sizeof(bookType), 1, binLib) && q<50) //fread zwroci 0 w przypadku konca pliku
    {
        library[q++]=book;
    }
    fclose(binLib);

    //sortowanie danych od najnowszych ksiazek
    for(int i=0; i<q; i++)
        for(int j=0; j<q; j++)
            if(library[i].year>library[j].year) swapBook(library, i, j);

    binLib=fopen("biblioteka.bin", "wb");
    fwrite(library, sizeof(bookType), q, binLib);
    fclose(binLib);

    binLib=fopen("biblioteka.bin", "rb");
    printf("Do pliku zapisano binarnie: \n");
    fread(library, sizeof(bookType), q, binLib);

    for(int i=0; i<q; i++)
    {
        printf("%s %s %d %d\n", library[i].author, library[i].title, library[i].year, library[i].size);
    }
    return 0;
}