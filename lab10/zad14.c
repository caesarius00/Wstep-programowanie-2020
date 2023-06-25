#include<stdio.h>
#include<string.h>
#include<stdbool.h>

// zwraca pierwszy element tablicy
// UWAGA: nie działa dla pustej tablicy
int head(int *tab);

// zwraca podtablicę złożoną ze wszystkich poza poza pierwszym elementem
// UWAGA: nie działa dla pustej tablicy
int* tail(int *tab);

// argumenty:
//  - tab1 - posortowana tablica zmiennych typu int
//  - n1   - liczba elementow w tab1
//  - tab2 - posortowana tablica zmiennych typu int
//  - n2   - liczba elementow w tab2
// zwracana wartosc:
//  true  - jezeli istnieje element, należacy do obu tablic albo
//  false - w przeciwnym przypadku
bool czyJestWspolny(int* tab1, int n1, int* tab2, int n2);

int main()
{
    int tab1[] = {1,2,4,4,6,8,8,8,8,10,11};
    int tab2[] = {3,5,5,5,6,7};

    if (czyJestWspolny(tab1, sizeof(tab1)/sizeof(tab1[0]), tab2, sizeof(tab2)/sizeof(tab2[0])))
        printf("Jest wspolny\n");
    else
        printf("Nie ma wspolnego\n");
}

int head(int *tab)
{
    return *tab;
}

int* tail(int *tab)
{
    return tab+1;
}

bool czyJestWspolny(int *tab1, int n1, int *tab2, int n2)
{
    if()
	for(int i=0; i<n1; i++)
    {
        for(int j=0; j<n2; j++)
        {
            if(tab1[i]==tab2[j]) return true;
        }
    }
	return false;
}