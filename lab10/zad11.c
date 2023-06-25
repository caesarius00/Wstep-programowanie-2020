#include <stdio.h>

int recurSum(int a)
{
    if(a%10==a) return a;
    else return a%10+recurSum(a/10);
}

int main()
{
    printf("%d", recurSum(966));
    return 0;
}