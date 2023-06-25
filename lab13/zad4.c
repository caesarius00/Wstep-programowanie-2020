#include <stdio.h>

int main()
{
    int n, c, count=1;
    printf("Podaj n - ilosc bitow to reprezentacji U1: ");
    scanf("%d", &n);
    printf("Podaj liczbe calkowita do zapisania w systemie U1 na %d bitach: ", n);
    scanf("%d", &c);
    if(c<0)
    {
        printf("1");
        for(int i=0; i<n-1; i++) count*=2;
        c-=(-1*count+1);
    }
    else printf("0");
    
    for(int i=n-1; i>0; i--)
    {
        count=1;
        for(int j=0; j<i-1; j++) count*=2;
        
        if(c>=count)
        {
            printf("1");
            c-=count;
        }
        else printf("0");
    }
    return 0;
}