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
    int x, lt=0, gt=0, eq=0;
    printf("Podaj liczbe: ");
    scanf("%d", &x);
    for(int i=0; i<20; i++)
    {
        if(tab[i]<x) lt++;
        else if(tab[i]>x) gt++;
        else eq++;
    }
    printf("Mniejszych od %d jest %d\n", x, lt);
    printf("Wiekszych od %d jest %d\n", x, gt);
    printf("Rownych %d jest %d\n", x, eq);

	/***** WYŚWIETLENIE ZAWARTOŚCI TABLICY ******/    
	printf("tab = [");
	for (int i=0; i<19; i++)
		 printf("%d, ", tab[i]);
	printf("%d]\n", tab[19]);
}
