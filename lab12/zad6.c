#define MAX_BOOKS 50
#include <stdio.h>

typedef struct
{
    char title[21];
    char author[21];
    int year;
    int size;
}bookType;

int main()
{
    FILE *binLib;
    bookType library[MAX_BOOKS], book;
    int q=0;
    binLib=fopen("biblioteka.bin", "r+b");
    while(fread(&book, sizeof(bookType), 1, binLib) && q<50)
    {
        book.size++;
        library[q++]=book;
    }
    fseek(binLib, 0, SEEK_SET);
    fwrite(library, sizeof(bookType), q, binLib);
    fseek(binLib, 0, SEEK_SET);
    printf("Dane zapisane do pliku binarnego: \n");
    while(fread(&book, sizeof(bookType), 1, binLib))
    {
        printf("%s %s %d %d\n", book.author, book.title, book.year, book.size);
    }
    return 0;
}