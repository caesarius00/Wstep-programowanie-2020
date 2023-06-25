#include <stdio.h>
#include <malloc.h>

int main()
{
    int ile, k, temp=0, temp2;
    printf("Podaj liczbe elementow tablicy: ");
    scanf("%d", &ile);
    printf("Przesunięcie w prawo o k pozycji, podaj k: ");
    scanf("%d", &k);
    int *tab=malloc(ile*sizeof(int));
    for(int i=0; i<ile; i++) tab[i]=i;
    printf("Przed:\n");
    for(int i=0; i<ile; i++) printf("%d, ", tab[i]);
    for(int i=0; i<ile; i++)
    {
        temp=tab[(i+k)%ile];
        tab[(i+k)%ile]=tab[i];
    }
    printf("\nPo\n");
    for(int i=0; i<ile; i++) printf("%d, ", tab[i]);

    return 0;
}