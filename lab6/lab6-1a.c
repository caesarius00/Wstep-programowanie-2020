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
	
	
	/***** Tutaj umieść rozwiązanie zadania ******/  
    int min=20, max=0, avg=0, counter;
	    for(int i=0; i<20; i++)
    {
        if(tab[i]>max) max=tab[i];
        if(tab[i]<min) min=tab[i];
        avg+=tab[i];
        counter++;
    }
    printf("Min: %d, max: %d, avg: %g, liczba operacji: %d\n", min, max, (float)avg/20, counter);
	
	/***** WYŚWIETLENIE ZAWARTOŚCI TABLICY ******/    
	printf("tab = [");
	for (int i=0; i<19; i++)
		 printf("%d, ", tab[i]);
	printf("%d]\n", tab[19]);
}
