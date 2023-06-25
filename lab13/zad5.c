#include <stdio.h>

int main()
{
    int c=0, n, bit, count=1;
    printf("Podaj n: ");
    scanf("%d", &n);
    printf("Podawaj kolejne bity w systemie U1:\n");
    scanf("%d", &bit);
    if(bit==1)
    {
        for(int i=0; i<n-1; i++) count*=2;
        c+=(-1*count+1);
    }
    n--;
    while(n)
    {
        scanf("%d", &bit);
        count=1;
        for(int i=0; i<n-1 && bit; i++) count*=2;
        c+=bit*count;
        n--;
    }
    printf("%d", c);
    return 0;
}