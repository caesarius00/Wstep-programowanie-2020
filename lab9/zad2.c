#include <stdio.h>

int max_sp1(int *arr, int size)
{
    int max=*arr;
    for(int i=1; i<size; i++)
    {
        if(arr[i]>max) max=arr[i];
    }
    return max;
}

int max_sp2(int *start, int *postEnd)
{
    int *point, max=*start;
    for(point=start+1; point !=postEnd; point++)
    {
        if(*point>max) max=*point;
    }
    return max;
}

int main()
{
    int arr[]={1,5,3,4,76,23,4,65};
    printf("Sposob 1: max(tab) = %d\n", max_sp1(arr, sizeof(arr)/sizeof(arr[0])));
    printf("Sposob 2: max(tab) = %d\n", max_sp2(arr, arr+sizeof(arr)/sizeof(arr[0])));
    return 0;
}