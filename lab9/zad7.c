#include <stdio.h>
#define SIZE sizeof(arr)/sizeof(arr[0])

void swap(int *number1, int *number2)
{
    int temp=*number1;
    *number1=*number2;
    *number2=temp;
}

void sort(int *arr, int size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=size-1; j>i; j--)
        {
            if(arr[j]<arr[i]) swap(arr+j, arr+i);
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
    int arr[]={0,1,1,1,0,0,1,0,1,1,0,0,0,1,1,0,1,1,0};
    sort(arr, SIZE);
    print(arr, SIZE);
    return 0;
}