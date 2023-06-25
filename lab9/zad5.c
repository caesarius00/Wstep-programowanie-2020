#include <stdio.h>
#define SIZE sizeof(arr)/sizeof(arr[0])

void add(int *arr, int k)  //funkcja przyjmuje jako 1 argument wskaznik na tablicę posortowaną
{
    int q=0, temp, temp2;
    for(int i=k-1; i>=0;)
    {
        if(arr[i]>arr[k]) i--;
        else if(arr[i]<=arr[k])
        {
            q=i+1;
            i-=k;
        }
    }
    temp=arr[q];
    arr[q]=arr[k];
    for(int i=q+1; i<k+1; i++) 
    {
        temp2=arr[i];
        arr[i]=temp;
        temp=temp2;
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
    int arr[]={1,67,32,43,1,0,99};

    for(int i=1; i<SIZE; i++)
    {
        add(arr, i);
    }
    print(arr, SIZE);
    return 0;
}