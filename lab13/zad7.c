#include <stdio.h>

int main()
{
    int n, c=0, count=1, bit;
    printf("Podaj ilosc bitow liczby: ");
    scanf("%d", &n);
    printf("Podawaj bity: ");
    scanf("%d", &bit);
    if(bit==1)
    {
        for(int i=0; i<n-1; i++) count*=2;
        c+=-1*count;
    }
    n--;
    while(n)
    {
        scanf("%d", &bit);
        count=1;
        for(int i=0; i<n-1 && bit; i++) count*=2;
        c+=bit*count;
        n--;
    }printf("%d", c);
    return 0;
}