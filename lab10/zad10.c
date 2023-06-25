#include <stdio.h>

int RekNWD(int a, int b)
{
    if(a==b) return a;
    else if(a>b) return RekNWD(a-b, b);
    else return RekNWD(a, b-a);
}

int main()
{
    printf("NWD=%d", RekNWD(70, 30));
    return 0;
}