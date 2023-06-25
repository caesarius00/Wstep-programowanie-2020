#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	/***** LOSOWANIE TABLICY ******/
	srand( time( NULL ) );      // inicjalizacja generatora liczb pseudolosowych
	int tab[20];                // deklaracja tablicy
	for (int i=0; i<20; i++)    // dla kazdego elementu
		 tab[i] = rand() % 20;   // 'wylosuj' liczbe z zakresu 0..19
	
	
	/***** Tutaj umieść rozwiązanie zadania ******/ 
    int szukana, indeks=20;
	printf("Podaj szukana liczbe: ");
    scanf("%d", &szukana);
    for(int i=0; i<20; i++) if(tab[i]==szukana) indeks=i;
	if(indeks<20) printf("Ostatnie wystąpienie liczby w tablicy: %d\n", indeks);
    else printf("Liczba nie wystepuje w tablicy\n");

	/***** WYŚWIETLENIE ZAWARTOŚCI TABLICY ******/    
	printf("tab = [");
	for (int i=0; i<19; i++)
		 printf("%d, ", tab[i]);
	printf("%d]\n", tab[19]);
}
