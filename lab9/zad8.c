#include <stdio.h>


int rozklad(int n, int start)
{
    if(n==1) return 1;
    else for(int i=start; i<n; i++) printf("%d ", rozklad(--n, i));
    printf("\n");
}

int main()
{
    int n;
    printf("Podaj liczbe naturanlna N: ");
    scanf("%d", &n);
    rozklad(n, 0);
    return 0;
}