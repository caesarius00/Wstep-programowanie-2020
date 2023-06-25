#include <stdio.h>

int main()
{
    float arr[10001], roznica;
    int x, l=0, r, m;
    printf("Podaj liczbe do spierwiastkowania (1; 2 000): ");
    scanf("%d", &x);
    for(int i=0; i<10001; i++)
    {
        arr[i]=(i+1)*0.1;
    }
    roznica=x;
    r=10*x;
    while(l<=r)
    {
        m=(l+r)/2;
        if(arr[m]*arr[m]<(float)x) l=m+1;
        else if(arr[m]*arr[m]>(float)x) r=m-1;
        else l=m+1;
    } 

    printf("Pierwiastek z dokladnoscia do 0.1: %f\n", arr[m]);
    return 0;
}