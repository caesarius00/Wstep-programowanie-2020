#include <stdio.h>

int main()
{
    int n, liczba13, liczba52, liczba21, suma=0;
    printf("Podaj n: ");
    scanf("%d", &n);

    //a
    for(int i=0; i<n; i++)
    {
        liczba13=13*(i+1);
    }
    printf("13: %d\n", liczba13);
    for(int i=0; i<n; i++)
    {
        liczba21=21*(i+1);
    }
    printf("21: %d\n", liczba21);
    for(int i=0; i<n; i++)
    {
        liczba52=52*(i+1);
    }
    printf("52: %d\n", liczba52);

    //b
    liczba13=0;
    liczba21=0;
    liczba52=0;
    int i=0;
    while(i<n)
    {
        liczba13=13*(i+1);
        liczba21=21*(i+1);
        liczba52=52*(i+1);
        i++;
    }
    printf("13: %d\n", liczba13);
    printf("21: %d\n", liczba21);
    printf("52: %d\n", liczba52);
    return 0;
}