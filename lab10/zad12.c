#include <stdio.h>

int liczbaCyfr(int a)
{
    int q=0;
    while(a>0)
    {
        a/=10;
        q++;
    }return q;
}

int main()
{
    printf("%d\n", liczbaCyfr(966));
    return 0;
}