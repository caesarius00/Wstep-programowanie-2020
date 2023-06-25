#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int wylosowana=rand()%101, uzytkownika=-1;
    while(wylosowana!=uzytkownika)
    {
        printf("Podaj liczbę z przedzialu <0;100>: ");
        scanf("%d", &uzytkownika);
        if(wylosowana>uzytkownika) printf("Za mala\n");
        else if(wylosowana<uzytkownika) printf("za duza\n");
        else printf("Brawo! To ta liczba! \n");
        
        
    }

    return 0;
}