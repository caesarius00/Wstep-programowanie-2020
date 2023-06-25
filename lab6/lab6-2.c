#include<time.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
	/***** LOSOWANIE TABLICY ******/
	srand( time( NULL ) );      // inicjalizacja generatora liczb pseudolosowych
	int tab[20];                // deklaracja tablicy
	for (int i=0; i<20; i++)    // dla kazdego elementu
		 tab[i] = rand() % 20;   // 'wylosuj' liczbe z zakresu 0..19
	
	
    int szukana, q=0;
	printf("Podaj liczbę do sprawdzenia: ");
    scanf("%d", &szukana);
    for(int i=0; i<20; i++) if(tab[i]==szukana) q++;
    if(q==1) printf("%d występuje w tablicy 1 raz\n", szukana);
	else printf("%d występuje w tablicy %d razy\n", szukana, q);
	
	/***** WYŚWIETLENIE ZAWARTOŚCI TABLICY ******/    
	printf("tab = [");
	for (int i=0; i<19; i++)
		 printf("%d, ", tab[i]);
	printf("%d]\n", tab[19]);
}
