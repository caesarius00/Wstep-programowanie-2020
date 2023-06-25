#include<time.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
	/***** LOSOWANIE TABLICY ******/
	srand( time( NULL ) );      // inicjalizacja generatora liczb pseudolosowych
	int tab[20];                // deklaracja tablicy
	tab[0] = rand() % 5;        // 'wylosuj' liczbe z zakresu 0...4
	for (int i=1; i<20; i++)    // dla kazdego elementu
		 tab[i] = tab[i-1] + rand() % 3;   // 'wylosuj' liczbe z zakresu 0...2 i dodaj do poprzedniego elementu
	
	/***** Tutaj umieść rozwiązanie zadania ******/    
	int min=tab[0], max=tab[19], avg=0, counter=0;
    for(int i=0; i<20; i++) 
    {
        avg+=tab[i];
        counter++;
    }
    printf("Min: %d, max: %d, avg: %g, ilosc operacji: %d\n", min, max, (float)avg/20, counter);
	
	/***** WYŚWIETLENIE ZAWARTOŚCI TABLICY ******/    
	printf("tab = [");
	for (int i=0; i<19; i++)
		 printf("%d, ", tab[i]);
	printf("%d]\n", tab[19]);
}
