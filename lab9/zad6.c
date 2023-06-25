#include <stdio.h>
#define SIZE sizeof(arr)/sizeof(arr[0])

void swap(int *number1, int *number2)
{
    int temp=*number1;
    *number1=*number2;
    *number2=temp;
}

void selection_sort(int *arr, int size)
{
    for(int i=0; i<size; i++)
    {
        int *min=arr+i;
        for(int j=i; j<size; j++)
        {
            if(arr[j]<*min) min=arr+j;
        }
        swap(arr+i, min);
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
    int arr[]={67,45,23,76,1,1,1,0};
    selection_sort(arr, SIZE);
    print(arr, SIZE);

    
    return 0;
}