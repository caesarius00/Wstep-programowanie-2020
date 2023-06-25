#include <stdio.h>
#include <string.h>

int zamiana(char *liczba, int size)
{
    int liczbaInt=0;
    for(int i=0; i<size; i++)
    {
        int j=size-i, mnoznik=1;
        while(j>1) 
        {
            mnoznik*=10;
            j--;
        }
        liczbaInt+=(liczba[i]-48)*mnoznik; //korzystajac z tablicy ascii (kod cyfry jest 48 wiekszy od jej wartosci)
    }
    return liczbaInt;
}

int main()
{
    char liczbaChar[]="275";
    int liczba=zamiana(liczbaChar, strlen(liczbaChar));
    printf("%d\n", liczba);
    return 0;
}