#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    char arr[10][10];
    for(int i=0; i<10; i++)
    {
        printf("arr[%d]: ", i);
        for(int j=0; j<10; j++)
        {
            //przypisuję losowo do tablicy kody ASCII dużych liter
            arr[i][j]=rand()%26+65;
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
    int notFound=1;
    for(int i=0; i<10 && notFound; i++)
    {
        for(int j=0; j<10 && notFound; j++)
        {
            if(arr[i][j]=='L')
            {
                //pętle sprawdzą każdy sąsiadujący element
                for(int k=-1; k<2 && notFound; k++)
                {
                    for(int l=-1; l<2 && notFound; l++)
                    {
                        //sprawdzam, czy indeksy nie wychodzą poza tablicę    
                        if(i+k>-1 && i+k<10 && j+l>-1 && j+l<10)
                        {
                            if(arr[i+k][j+l]=='O')
                            {
                                //znowu sprawdzam, czy indeksy nie wychodzą poza tablicę    
                                if(i+2*k>-1 && i+2*k<10 && j+2*l>-1 && j+2*l<10)
                                {
                                    if(arr[i+2*k][j+2*l]=='S')
                                    {
                                        notFound=0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(notFound) printf("Nie znaleziono slowa LOS\n");
    else printf("Znaleziono slowo LOS\n");

    return 0;
}