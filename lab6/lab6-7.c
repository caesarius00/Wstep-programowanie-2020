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
	
	int l=0, r=19, m, x, lt=0, gt=0, eq=0, indeksMax=20, indeksMin=20, q=0;
    printf("Podaj liczbe: ");
    scanf("%d", &x);
    while(l<=r)
    {
        m=(l+r)/2;
        if(tab[m]<x) 
        {
            l=m+1;
        }
        else if(tab[m]>x) 
        {
            r=m-1;
        }
        else 
        {
            if(indeksMax=20) //jest to pierwsze znalezienie liczby
            {
                for(int j=m; j>=0;j--)
                {
                    if(tab[j]==x) indeksMin=j;
                    else j=0;
                }
            }
            indeksMax=m;
            l=m+1;
        }
    }   
    if(indeksMin!=20)  //jeśli jest conajmniej jedna szukana liczba
    {
        gt=19-indeksMax;
        eq=indeksMax-indeksMin+1;
        lt=indeksMin;
    }
    else
    {
        if(tab[m]>x) q=1;
        gt=19-m+q;
        lt=1+m-q;
    }
    printf("Liczb mniejszych od %d jest %d\n", x, lt);
    printf("Liczb wiekszych od %d jest %d\n", x, gt);
    printf("Liczb rownych %d jest %d\n", x, eq);
	
	/***** WYŚWIETLENIE ZAWARTOŚCI TABLICY ******/    
	printf("tab = [");
	for (int i=0; i<19; i++)
		 printf("%d, ", tab[i]);
	printf("%d]\n", tab[19]);
}
