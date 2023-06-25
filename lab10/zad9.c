#include <stdio.h>

int silnia(int a)
{
    if(a==0) return 1;
    int iloczyn=1;
    for(int i=1;i<=a;i++) iloczyn*=i;
    return iloczyn;
}

int main()
{
    int a=6;
    printf("Silnia: %d", silnia(a));
    return 0;
}