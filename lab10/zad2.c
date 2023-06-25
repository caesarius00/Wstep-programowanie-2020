#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char imie[20], nazwisko[30], dane[55]={"\0"}, wiekStr[4];
    int wiek;
    printf("Podaj imie, nazwisko i wiek:");
    scanf("%s%s%d", imie, nazwisko, &wiek);
    strcat(dane, imie);
    strcat(dane, ", ");
    strcat(dane, nazwisko);
    strcat(dane, ", wiek: ");
    sprintf(wiekStr, "%d", wiek);
    strcat(dane, wiekStr);
    printf("%s", dane);
    return 0;
}