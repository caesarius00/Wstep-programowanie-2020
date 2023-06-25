#include <stdio.h>

int main()
{
    int h;
    printf("Podaj wysokosc: ");
    scanf("%d", &h);
    for(int i=1; i<h+1; i++)
    {
        for(int j=i; j<=i*i; j+=i)
        {
            printf("%d ", j);
        }

        printf("\n");
    }
    return 0;
}