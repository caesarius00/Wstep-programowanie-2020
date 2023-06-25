#include <stdio.h>
#include "rational.h"

int main()
{
    int k;
    rationalNumb x, result;
    result.nominator=1;
    result.denominator=1;
    printf("Podaj k: ");
    scanf("%d", &k);
    for(int i=2; i<k+1; i++)
    {
        x.nominator=1;
        x.denominator=i;
        result=sum(result, x);
    }
    printf("Suma wynosi: %d / %d", result.nominator, result.denominator);
    return 0;
}