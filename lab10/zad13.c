#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char *rewers(char *str, int znak)
{
    if(znak==0) return str;
    else 
    {
        char *napis=(char*)malloc(znak*sizeof(char)); 
        //błąd pewnie jest tutaj w tym, że nie mogę użyć strcat, bo nic nie ma w zmiennej "napis", ale nie wiem jak to naprawić
        napis=rewers((str), znak-1);
        return strcat(napis, str+znak-1);
    }
}

int main()
{
    printf("%s", rewers("test", 4));
    return 0;
}