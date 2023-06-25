#include <stdio.h>
#define SIZE sizeof(arr)/sizeof(arr[0])

void swap(int *number1, int *number2)
{
    int temp=*number1;
    *number1=*number2;
    *number2=temp;
}

int count_elem(int *arr, int size)
{
    int flag=0, count=0;
    for(int i=0; i<size && flag!=1; i++)
    {
        if(arr[i]==-1) flag=1;
        else count++;
    }
    return count;
}

int check_elem(int *arr, int size)
{
    int flag=0, elem, where=-1;
    printf("Podaj liczbe: ");
    scanf("%d", &elem);
    for(int i=0; i<size && flag!=1; i++)
    {
        if(arr[i]==elem) 
        {
            where=i;
            flag=1;
        }
    }
    if(flag) printf("Liczba %d nalezy do zbioru", elem);
    else printf("Liczba %d nie nalezy do zbioru", elem);
    return where;
}

void add(int *arr, int size)
{
    int elem;
    printf("Podaj element, ktory chcesz dodac: ");
    scanf("%d", &elem);
    arr[count_elem(arr, size)]=elem;
}

void remove_elem(int *arr, int size)
{
    int elem, flag=0, where=check_elem(arr, size);  //funkcja poprosi o element i znajdzie jego pozycje
    if(where!=-1)
    {
        printf(" i juz ja usuwam");
        arr[where]=-1;
        for(int i=where; i<size && flag==0; i++) 
        {
            if(arr[i+1]!=-1) swap(arr+i, arr+i+1);
            else flag=1;
        }
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
    char choice='e';
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,-1,-1,-1,-1,-1,-1};
    printf("Liczba elementów: %d\n", count_elem(arr, SIZE));
    count_elem(arr, SIZE);
    check_elem(arr, SIZE);
    printf("\n");
    add(arr, SIZE);
    remove_elem(arr, SIZE);
    printf("\n");
    print(arr, SIZE);

    return 0;
}