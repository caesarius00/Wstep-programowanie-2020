#include <stdio.h>

int main()
{
    int h;
    printf("Podaj wysokosc litery A: ");
    scanf("%d", &h);
    for(int i=0; i<h; i++)
    {
        if(i==0)
        {
            for(int j=0; j<h; j++) printf(" ");
            printf("A\n");
        }
        else if(i==h/2)
        {
            for(int j=h/2; j<h; j++) printf(" ");
            for(int j=0; j<h; j++) printf("A");     //tu bylo j<h/2
            printf("\n");
        }
        else
        {
            for(int j=i; j<h; j++) printf(" ");
            printf("A");
            for(int j=i*2; j>0; j--) printf(" ");   //tu było j=i
            printf("A\n");
        }
    }
    return 0;
}