#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    //zad1
    int arr[20];
    for(int i=0; i<20; i++) arr[i]=i+1;

    //zad2
    printf("Elementy tablicy: \n");
    for(int i=0; i<20; i++) printf("%d, ", arr[i]);
    printf("\n");

    //zad3
    int arr2[19], a;
    printf("Podaj ilosc elementow tablicy ( <20 ): ");
    scanf("%d", &a);
    for(int i=0; i<a; i++)
    {
        if(i<2) arr2[i]=i;
        else arr2[i]=arr2[i-2]+arr2[i-1];
    }
    printf("Elementy tablicy:\n");
    for(int i=0; i<a; i++) printf("%d, ", arr2[i]);
    printf("\n");

    //zad4
    int arr3[99], ilosc;
    printf("Podaj ilosc elementow tablicy ( <100 ): ");
    scanf("%d", &ilosc);
    printf("Podaj elementy tablicy: ");
    for(int i=0; i<ilosc; i++) scanf("%d", arr3+i);
    printf("Odwrotna kolejnosc: ");
    for(int i=ilosc-1; i>=0; i--) printf("%d, ", arr3[i]);
    printf("\n");

    //zad5
    int arr4[99], arr5[99], ilosc2;
    printf("Podaj ilosc elementow tablicy ( <100 ): ");
    scanf("%d", &ilosc2);
    printf("Podaj elementy tablicy: ");
    for(int i=0; i<ilosc2; i++)
    {
        scanf("%d", arr4+i);
        arr5[ilosc2-1-i]=arr4[i];
    }
    printf("Elementy tablicy:\n");
    for(int i=0; i<ilosc2; i++) printf("%d, ", arr5[i]);
    printf("\n");

    //zad6
    int arr6[99], ilosc3, temp;
    printf("Podaj ilosc elementow tablicy ( <100 ): ");
    scanf("%d", &ilosc3);
    printf("Podaj elementy tablicy: ");
    for(int i=0; i<ilosc3; i++) scanf("%d", arr6+i);
    for(int i=0; i<ilosc3/2; i++)
    {
        temp=arr6[i];
        arr6[i]=arr6[ilosc3-1-i];
        arr6[ilosc3-1-i]=temp;
    }
    printf("Elementy tablicy:\n");
    for(int i=0; i<ilosc3; i++) printf("%d, ", arr6[i]);
    printf("\n");

    //zad7
    int tab[9999], ilosc4;
    printf("Podaj ilosc liczb do sprawdzenia ( 1 < n < 10 000 ): ");
    scanf("%d", &ilosc4);
    for(int i=2; i<=ilosc4; i++) tab[i]=1;
    for(int i=2; i<sqrt(ilosc4); i++)
    {
        if (tab[i]==1)
        {
            for(int j=2*i; j<ilosc4; j+=i)
            {
                if(j%i==0) tab[j]=0;
            }
        }
    }
    printf("Liczby pierwsze <= n: ");
    for(int i=2; i<ilosc4; i++)
    {
        if(tab[i]==1) printf("%d, ", i);
    }

    //zad8
    srand(time(NULL));
    int tab2[20], tab3[20];
    for(int i=0; i<20; i++) tab2[i]=rand()%20;
    tab3[0]=0;
    for(int i=1; i<20; i++)
    {
        tab3[i]=tab3[i-1]+tab2[i-1];
    }
    printf("tab = [");
    for(int i=0; i<19; i++) printf("%d, ", tab3[i]);
    printf("%d]\n", tab3[19]);

    //zad9
    //srand(time(NULL)); //gdyby było uruchamiane osobno od zad8
    int liczby[20], min=20, max=0, avg=0;
    for(int i=0; i<20; i++) liczby[i]=rand()%20;
    for(int i=0; i<20; i++)
    {
        if(liczby[i]>max) max=liczby[i];
        if(liczby[i]<min) min=liczby[i];
        avg+=liczby[i];
    }
    printf("Elementy tablicy:\n");
    for(int i=0; i<20; i++) printf("%d, ", liczby[i]);
    printf("\nMaks=%d\nMin=%d\nSrednia=%d\n", max, min, avg/20);
    //zad10    
    //srand(time(NULL)); //gdyby było uruchamiane osobno od zad8
    int liczby2[20], max1=0, max2=0;
    for(int i=0; i<20; i++) liczby2[i]=rand()%20;
    for(int i=0; i<20; i++)
    {
        if(liczby2[i]>max1) 
        {
            max2=max1;
            max1=liczby2[i];
        }
        else if(liczby[i]>max2 && liczby[i]<max1) max2=liczby2[i];
    }
    printf("Elementy tablicy:\n");
    for(int i=0; i<20; i++) printf("%d, ", liczby2[i]);
    printf("\nDruga najwieksza liczba: %d\n", max2);

    //zad11
    //srand(time(NULL)); //gdyby było uruchamiane osobno od zad8
    int liczby3[20], max11=0, max22, maxIndex=0;
    for(int i=0; i<20; i++) liczby3[i]=rand()%20;
    for(int i=0; i<20; i++)
    {
        if(liczby3[i]>max11) 
        {
            max22=maxIndex;
            maxIndex=i;
            max11=liczby3[i];
        }
        else if(liczby3[i]>liczby3[max22] && liczby3[i]<max11) max22=i;
    }
    printf("Elementy tablicy:\n");
    for(int i=0; i<20; i++) printf("%d, ", liczby3[i]);
    printf("Drugi największy element tablicy to tab[%d]\n", max22);

    //zad12
    int liczby4[20], swap;
    for(int i=0; i<20; i++) liczby4[i]=rand()%20;
    for(int i=0; i<19; i++)
    {
        for(int j=0; j<19; j++)
        {
            if(liczby4[j]>liczby4[j+1])
            {
                swap=liczby4[j];
                liczby4[j]=liczby4[j+1];
                liczby4[j+1]=swap;
            }
        }
    }
    printf("Elementy tablicy:\n");
    for(int i=0; i<20; i++) printf("%d, ", liczby4[i]);

    return 0;
}