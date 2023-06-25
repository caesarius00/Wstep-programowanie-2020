#define N 10        //ilosc wierszy
#define M 10        //ilosc kolumn
#define ZAKRES 4    //zakres n oznacza liczby losowane z przedziału 0, 1, 2, ..., n-1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


//funkcja policzy sumę dla podtablicy 2x2
//start - zmienne przechowujace indeksy na lewy gorny rog tej podtablicy 
int sum2x2(int arr[N][M], int startRow, int startColumn)
{
    int sum=0;
    for(int i=startRow; i<startRow+2; i++)
    {
        for(int j=startColumn; j<startColumn+2; j++) sum+=arr[i][j];
    }
    return sum;
}

int main()
{
    //zad1
    srand(time(NULL));
    int arr[N][M];
    printf("Tablica:\n");
    for(int i=0; i<N; i++)
    {
        printf("arr[%d]: ", i);
        for(int j=0; j<M; j++) 
        {
            arr[i][j]=rand()%ZAKRES;
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    //zad2
    int noZero=0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(arr[i][j]) noZero++;
        }
    }
    printf("Tablica ma %d elementow niezerowych\n", noZero);

    //zad3
    int sum[N];
    for(int i=0; i<N; i++)
    {
        sum[i]=0;
        for(int j=0; j<M; j++) sum[i]+=arr[i][j];
    }
    int max=sum[0], index=0;
    for(int i=1; i<N; i++)
    {
        if(sum[i]>max)
        {
            index=i;
            max=sum[i];
        }
    }
    printf("Rzad %d ma najwieksza sume rowna %d\n", index, max);

    //zad4
    int minSum, minRow, minCol;
    for(int i=0; i<N-1; i++)
    {
        for(int j=0; j<M-1; j++)
        {
            int rowSum=sum2x2(arr, i, j);
            if(!i)
            {
                minSum=rowSum;
                minRow=i;
                minCol=j;
            }
            else if(rowSum<minSum)
            {
                minSum=rowSum;
                minRow=i;
                minCol=j;
            }
        }
    }
    printf("Najmniejsza sume ma podtablica o wspolrzednych od [%d][%d] do [%d][%d] i wynosi %d\n", minRow, minCol, minRow+1, minCol+1, minSum);
    return 0;
}