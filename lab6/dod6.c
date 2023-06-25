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
	int count[20][2];   //tablica reprezentujaca [i][0] - liczbe oraz [i][1] - jej ilosc
    int q=0;            //ilosc roznych liczb w tablicy
    int temp=0;              
    for(int i=0; i<20; i++) count[i][1]=0;
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<q; j++)
        {
            if(tab[i]==count[j][0])
            {
                count[j][1]++;
                temp++;
            }
        }
        if(temp==q)     //jeśli ta liczba nie jest jeszcze zapisana w tablicy count
        {
            count[q][0]=tab[i];
            count[q][1]++;
            temp=++q;
        }
        temp=q;
    }
    for(int i=0; i<20; i++)
    {
        if(count[i][1]!=0) printf("Liczba %d wystepuje %d razy\n", count[i][0], count[i][1]);
    }

	
	/***** WYŚWIETLENIE ZAWARTOŚCI TABLICY ******/    
	printf("tab = [");
	for (int i=0; i<19; i++)
		 printf("%d, ", tab[i]);
	printf("%d]\n", tab[19]);
}
