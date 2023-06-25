#include <stdio.h>
#include <math.h>


int liczba_cyfr(unsigned long long int liczba);
short int czy_pierwsza(int liczba);
short int pitagores(int a, int b, int c);
int kwadrat(int x);
void inc(int *liczba);
void swap(int *a, int *b);
void sort(int *a, int *b, int *c, int *d);
void f_1zad9();
void f_2zad9();
void f_3zad9();

int main()
{/*
    //zad1
    unsigned long long int zad1;
    printf("Podaj liczbe do sprawdzenia liczby cyfr: ");
    scanf("%llud", &zad1);
    printf("Liczba cyfr: %d\n", liczba_cyfr(zad1));

    //zad2
    int zad2;
    printf("Podaj liczbe do sprawdzenia: ");
    scanf("%d", &zad2);
    if(zad2<1) printf("Nie jest to liczba naturalna\n");
    else if(czy_pierwsza(zad2)) printf("%d jest liczba pierwsza\n", zad2);
    else printf("%d nie jest liczba pierwsza\n", zad2);

    //zad3
    int zad3a, zad3b, zad3c;
    printf("Podaj 3 liczby: ");
    scanf("%d %d %d", &zad3a, &zad3b, &zad3c);
    if(pitagores(zad3a, zad3b, zad3c)) printf("Sa to liczby pitagorejskie\n");
    else printf("Nie sa to liczby pitagorejskie\n");

    //zad4
    int zad4, temp=0;
    printf("Podaj zakres [1;n]: ");
    scanf("%d", &zad4);
    printf("Trojki pitagorejskie [1; %d]: \n", zad4);
    for(int i=1; i<=zad4; i++)
    {
        for(int j=i; j<=zad4; j++)
        {   
            for(int k=j; k<=zad4; k++)
            {
                if(pitagores(i, j, k)) 
                {
                    printf("%d %d %d; ", i, j, k);
                    temp++;
                }
            }
        }
    }
    if(!temp) printf("Brak");
    printf("\n");

    //zad5
    int zad5;
    printf("Podaj liczbe x>=1: ");
    scanf("%d", &zad5);
    if(zad5==sqrt(kwadrat(zad5))) printf("%d == pierwiastek(kwadrat(%d))\n", zad5, zad5);
    else printf("%d != pierwiastek(kwadrat(%d))\n", zad5, zad5);

    //zad6
    int zad6;
    printf("Podaj liczbe do zwiekszenia: ");
    scanf("%d", &zad6);
    inc(&zad6);
    printf("Powiekszona liczba: %d\n", zad6);

    //zad7
    int zad7a, zad7b;
    printf("Podaj liczby do zamienienia: ");
    scanf("%d %d", &zad7a, &zad7b);
    swap(&zad7a, &zad7b);
    printf("Zamienione liczby: %d %d\n", zad7a, zad7b);

    //zad8
    int a, b, c, d;
    printf("Podaj 4 liczby: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    sort(&a, &b, &c, &d);
    printf("Posortowane: %d %d %d %d\n", a, b, c, d);
*/
    //zad9
    unsigned int zadanie=0;
    do
    {
        printf("Co chcesz zrobic:\n");
        printf("1 - sprawdzic czy liczba jest pierwsza\n");
        printf("2 - sprawdzic czy liczba jest suma dwoch kwadratow\n");
        printf("3 - policzyc sume cyfr liczby\n");
        printf("4 - zakonczyc dzialanie programu\n");
        scanf("%u", &zadanie);
        if(zadanie==1)
        {
            f_1zad9();
        }
        else if(zadanie==2)
        {
            f_2zad9();
        }
        else if(zadanie==3)
        {
            f_3zad9();
        } else if(zadanie!=4) printf("Nie ma takiego numeru!\n");
        
    } while (zadanie!=4);

    return 0;
}

int liczba_cyfr(unsigned long long int liczba)
{
    int cyfry=0;
    while(liczba>9)
    {
        liczba=liczba/10;
        cyfry++;
    }
    cyfry++;
    return cyfry;
}

short int czy_pierwsza(int liczba)
{
    short int q=1;
    if(liczba==1 || liczba==2) q=1;
    else
    {
        for(int i=2; i<=sqrt(liczba); i++)
        {
            if(liczba%i == 0) q=0;
        }
    }
    return q;
}

short int pitagores (int a, int b, int c)
{
    if(a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a) return 1;
    else return 0;
}

int kwadrat(int x)
{
    return x*x;
}

void inc(int *liczba)
{
    (*liczba)++;
}

void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void sort(int *a, int *b, int *c, int *d)
{
    int *tab[4] = {a, b, c, d};
    for(int i=0; i<4; i++)
    {
        for(int j=i; j<4; j++)
        {
            if(*tab[i]>*tab[j]) swap(*(tab+j), *(tab+i));
        }
    }
}

void f_1zad9()
{

    int zad91;
    printf("Podaj liczbe do sprawdzenia: ");
    scanf("%u", &zad91);
    if(zad91<1) printf("Nie jest to liczba naturalna\n");
    else if(czy_pierwsza(zad91)) printf("%d jest liczba pierwsza\n", zad91);
    else printf("%d nie jest liczba pierwsza\n", zad91);
}

void f_2zad9()
{
    unsigned int zad92;
    short int flag=1;
    printf("Podaj liczbe do sprawdzenia: ");
    scanf("%u", &zad92);
    for(int i=1; i<zad92 && flag==1; i++)
    {
        for(int j=1; j<zad92; j++)
        {
            if(kwadrat(i)+kwadrat(j)==zad92) 
            {
                printf("Tak: %d^2+%d^2=%d", i, j, zad92);
                flag=0;
                break;
            }
        }
    }
    if(flag) printf("Nie da się jej tak przedstawic");
    printf("\n");
}

void f_3zad9()
{

    unsigned int zad93, suma=0;
    printf("Podaj liczbe naturalna: ");
    scanf("%u", &zad93);
    while(zad93>0)
    {
        suma+=zad93%10;
        zad93/=10;
    }
    printf("Suma cyfr: %u\n", suma);
}