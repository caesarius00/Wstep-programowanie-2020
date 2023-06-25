#include <stdio.h>


int sum_sp1(int *arr, int size)
{
    int sum=0;
    for(int i=0; i<size; i++) sum+=arr[i];
    return sum;
}

int sum_sp2(int *start, int *postEnd)
{
    int *pointer, sum=0;
    for(pointer=start; pointer!=postEnd; pointer++) sum+=*pointer;
    return sum;
}

int main()
{
    int arr[]={1,3,5,3,67,12,43,0,234};
    printf("Sposob 1: suma elementow tab = %d\n", sum_sp1(arr, sizeof(arr)/sizeof(arr[0])) );
    printf("Sposob 2: suma elementow tab = %d\n", sum_sp2(arr, arr+sizeof(arr)/sizeof(arr[0])) );
    return 0;
}