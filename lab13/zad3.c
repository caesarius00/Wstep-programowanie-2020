#include <stdio.h>

int main()
{
    int n, count=0, number=0, add;
    printf("Podaj ilosc bitow liczby n:");
    scanf("%d", &n);
    printf("Podaj kolejne bity rozdzielone spacja lub enterem:\n");
    while(n>count)
    {
        scanf("%hu", &add);
        count++;
        for(int i=0; i<n-count && add; i++)
        {
            add*=2;
        }
        number+=add;
    }
    printf("%d", number);
    return 0;
}