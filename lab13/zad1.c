#define MAX_BYTES 4
#include <stdio.h>

int main()
{
    unsigned int n, binary[MAX_BYTES*8], size=0;
    scanf("%d", &n);
    while(n && size <MAX_BYTES*8)
    {
        binary[size++]=n%2;
        n/=2;
    }
    while(size) printf("%d", binary[--size]);
    return 0;
}