#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void random_fill_sp1(int *arr, int size)
{
    for(int i=0; i<size; i++) arr[i]=rand()%100;
}
void random_fill_sp2(int *arr, int *postEnd)
{
    int *pt;
    {
        for(pt=arr; pt!=postEnd; pt++) *pt=rand()%100;
    }
}

void print(int *arr, int size)
{
    printf("Tablica = {");
    for(int i=0; i<size-1; i++) printf("%d, ", arr[i]);
    printf("%d}\n", arr[size-1]);
}

int main()
{
    srand(time(NULL));
    int arr[20], tab[20];
    random_fill_sp1(arr, sizeof(arr)/sizeof(arr[0]));
    random_fill_sp2(tab, tab+sizeof(tab)/sizeof(tab[0]));
    print(arr, sizeof(arr)/sizeof(arr[0]));
    print(tab, sizeof(tab)/sizeof(tab[0]));
    return 0;
}