#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	/***** LOSOWANIE TABLICY ******/
	srand( time( NULL ) );      // inicjalizacja generatora liczb pseudolosowych
	int tab[20];                // deklaracja tablicy
	tab[0] = rand() % 5;        // 'wylosuj' liczbe z zakresu 0...4
	for (int i=1; i<20; i++)    // dla kazdego elementu
		 tab[i] = tab[i-1] + rand() % 3;   // 'wylosuj' liczbe z zakresu 0...2 i dodaj do poprzedniego elementu
	
	int l=0, r=19, m, szukana, q=0, indeks=20;
    printf("Podaj szukana liczbe: ");
    scanf("%d", &szukana);
    while(l<=r)
    {
        m=(l+r)/2;
        if(tab[m]<szukana) l=m+1;
        else if(tab[m]>szukana) r=m-1;
        else 
        {
            indeks=m;
            l=m+1;
        }
    }   
	if(indeks<20) printf("Ostatni indeks w tablicy: %d\n", indeks);
    else printf("%d nie wystepuje w tablicy\n", szukana);
	
	/***** WYŚWIETLENIE ZAWARTOŚCI TABLICY ******/    
	printf("tab = [");
	for (int i=0; i<19; i++)
		 printf("%d, ", tab[i]);
	printf("%d]\n", tab[19]);
}
