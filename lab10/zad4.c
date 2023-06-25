#include <stdio.h>
#define SIZE sizeof(str)/sizeof(str[0])


void zmiana(char *str, int size)
{
    for(int i=0; i<size; i++)
    {
        //Zmieniamy duże litery na małe, korzystając z tablicy ASCII - kod małych liter jest o 32 większy
        if(str[i]>='A' && str[i]<='Z') str[i]+=32;
        //małe litery "a".."y" zmieniamy na kolejną w alfabecie (dużą), a "z" jako "A"
        else if(str[i]>='a' && str[i]<='y') str[i]-=31;
        else if(str[i]=='z') str[i]='A';
        //cyfry 0..8 zwiekszamy o 1, a 9 zapisujemy jako 0
        else if(str[i]>='0' && str[i]<='8') str[i]+=1;
        else if(str[i]=='9') str[i]='0';
    }
}

int main()
{
    char str[]="NaPiS DoZmIeNieNiA0123456789";
    zmiana(str, SIZE);
    printf("Zmieniony napis: %s", str);
    return 0;
}