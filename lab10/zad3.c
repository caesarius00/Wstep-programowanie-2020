#include <stdio.h>
#define SIZE sizeof(str)/sizeof(str[0])


int samogloski(char *str, int size)
{
    int q=0;
    for(int i=0; i<size; i++)
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' ) q++;
    return q;
}

int main()
{
    char str[]="Lancuch do obliczenia\0";
    printf("Liczba samoglosek: %d", samogloski(str, SIZE));

    return 0;
}