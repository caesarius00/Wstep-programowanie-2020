#define SIZE sizeof(str)/sizeof(str[0])
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char maxChar(char *str, int size)
{
    char *character=(char *) malloc(size*sizeof(char));
    int *value=(int *) malloc(size*sizeof(int));
    int saved=0;
    if(character == NULL || value == NULL) return(printf("Koniec pamieci\n"));
    else
    {
        //wczytywanie po kolei znakow z tablicy z zapisanym zdaniem
        for(int i=0; i<size; i++)
        {
            int flag=0;
            for(int j=0; j<=i; j++)
            {
                //sprawdzanie, czy znak juz wystapil i jest zliczona jego ilosc
                if(character[j]==str[i]) 
                {
                    value[j]++;
                    flag=1;
                }
            }
            //jesli znak sie pojawil pierwszy raz w zdaniu, to zaczyna byc liczona ilosc jego wystapien
            if(!flag) 
            {
                //zapisywanie nowego charakteru do tablicy
                character[saved]=str[i];
                value[i]=1;
                saved++;
            }
        }
    }
    int max=0;
    char maxChar;
    //sprawdzanie, ktory ze znakow wystepuje najwiecej razy
    for(int i=0; i<saved; i++)
    {
        if(value[i]>max)
        {
            max=value[i];
            maxChar=character[i];
        }
    }
    free(character);
    free(value);
    return maxChar;
}

int main()
{
    char str[]="Lancuch do sprawdzenia znakowwwwwwww";
    printf("Znak z najwieksza liczba wystapien: %c\n", maxChar(str, SIZE));
    return 0;
}