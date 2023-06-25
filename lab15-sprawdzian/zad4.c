#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sum()
{
    FILE *koszyk=fopen("plik.txt", "r");
    char var[50];
    int i=0;
    float sum=0;
    while(fscanf(koszyk, "%s", var)!=EOF)
    {
        if(i%2)
        {
            sum+=atof(var);
        }
        i++;
    }
    printf("Suma wynosi: %f", sum);
    fclose(koszyk);
}

void add()
{
    FILE *koszyk=fopen("plik.txt", "a");
    char var[50];
    printf("Podaj nazwe produktu: ");
    scanf("%s", var);
    fprintf(koszyk, "\n%s ", var);
    printf("Podaj cene: ");
    scanf("%s", var);
    fprintf(koszyk, "%s\n", var);
    fclose(koszyk);
}

void removeLine()
{
    FILE *temp=fopen("tymczasowy.txt", "w+");
    FILE *koszyk=fopen("plik.txt", "r+");
    char c;
    while(c=fgetc(koszyk)!=EOF) fprintf(temp, "%c", c);
    printf("Podaj numer produktu do usuniecia: ");
    int line;
    scanf("%d", &line);
    int i=1;
    while(c=fgetc(temp)!=EOF)
    {
        if(i!=line)
        {
            fprintf(koszyk, "%c", c);
        }
        if(c=='\n') i++;
    }
    fclose(temp);
    fclose(koszyk);
    remove(temp);
}

int main()
{
    int choice=1;
    while(choice)
    {
        printf("1 - wyswietl sume kosztow\n2 - dodaj nowa pozycje\n3 - usun wybrana pozycje\n0 - wyjscie\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: sum();
            break;
        
        case 2: add();
            break;
        case 3: removeLine();
            break;
        }
    }
    return 0;
}