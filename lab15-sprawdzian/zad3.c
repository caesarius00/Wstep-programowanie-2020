#include <stdio.h>

int secondMin(int *arr, int *afterArr)
{
    int min=*arr;
    int secondMin=*arr;
    for(int *i=arr; i!=afterArr; i++)
    {
        if(*i<min)
        {
            secondMin=min;
            min=*i;
        }
        else if(*i<secondMin && *i!=min) secondMin=*i;
        else if(*i>min && min==secondMin) secondMin=*i;
    }
    return secondMin;
}

int howMany(int *arr, int *afterArr, int n)
{
    int counter=0;
    for(int *i=arr; i!=afterArr; i++)
    {
        if(*i==n) counter++;
    }
    return counter;
}

int main()
{
    int arr[10];
    for(int i=0; i<10; i++) scanf("%d", arr+i);
    int sMin=secondMin(arr, arr+10);
    printf("%d wystapilo %d razy", sMin, howMany(arr, arr+10, sMin));
    return 0;
}