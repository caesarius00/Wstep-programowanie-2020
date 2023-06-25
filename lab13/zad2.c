#define MAX_BYTES 4
#include <stdio.h>

int main()
{
    int n, octal[MAX_BYTES*3], size=0;
    scanf("%d", &n);
    while(n)
    {
        octal[size++]=n%8;
        n/=8;
    }
    while(size)
    {
        printf("%d", octal[--size]);
    }
    return 0;
}