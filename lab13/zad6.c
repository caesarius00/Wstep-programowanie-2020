#include <stdio.h>

int main()
{
    int c, n, count=1;
    printf("Podaj n - ilosc bitow: ");
    scanf("%d", &n);
    printf("Podaj liczbe do przedstawienia w U2: ");
    scanf("%d", &c);
    if(c<0)
    {
        printf("1");
        for(int i=0; i<n-1; i++) count*=2;
        c-=(-1*count);
        n--;
    }
    while(n)
    {
        count=1;
        for(int i=0; i<n-1; i++) count*=2;
        if(c>=count)
        {
            printf("1");
            c-=count;
        }
        else printf("0");
        n--;
    }
    return 0;
}