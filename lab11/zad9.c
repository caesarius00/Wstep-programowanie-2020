#define MAX_LETTERS 10
#include <stdio.h>
#include <string.h>


typedef struct
{
    char nomen[MAX_LETTERS];
    char cognomen[MAX_LETTERS];
    union
    {
        unsigned long long int PESEL;
        unsigned int NIP;
    };
   enum genus {NIP, PESEL} variusGenus;
}laborator;

void addePESEL(laborator *laboratorX)
{
    unsigned long long int variaPESEL;
    printf("Podaj PESEL prawocnika, jesli wcześniej podano NIP, zostanie on usuniety:");
    scanf("%llu", &variaPESEL);
    laboratorX->PESEL=variaPESEL;
    laboratorX->variusGenus=PESEL;
}
void addeNIP(laborator *laboratorX)
{
    unsigned int variaNIP;
    printf("Podaj NIP prawocnika, jesli wcześniej podano PESEL, zostanie on usuniety:");
    scanf("%u", &variaNIP);
    laboratorX->NIP=variaNIP;
    laboratorX->variusGenus=NIP;
}
void monstraLaboratoris(laborator laboratorX)
{
    printf("Imie pracownika: %s\n", laboratorX.nomen);
    printf("Nazwisko pracownika: %s\n", laboratorX.cognomen);
    if(laboratorX.variusGenus==PESEL) printf("PESEL pracownika: %llu\n", laboratorX.PESEL);
    if(laboratorX.variusGenus==NIP) printf("NIP pracownika: %u\n", laboratorX.NIP);

}


int main()
{
    laborator laboratorPrimus;
    strcpy(laboratorPrimus.nomen, "Julius");
    strcpy(laboratorPrimus.cognomen, "Caesar");
    addeNIP(&laboratorPrimus);
    addePESEL(&laboratorPrimus);
    monstraLaboratoris(laboratorPrimus);
    return 0;
}