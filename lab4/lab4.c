#include <stdio.h>
#include <math.h>

int main()
{
    //zad1
    unsigned int n, m;
    printf("Podaj 2 liczby stanowiace rozmiar tabliczki mnozenia: ");
    scanf("%u%u", &n, &m);
    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<m+1; j++)
        {
            printf("%d*%d=%d\t", i, j, i*j );
        }
        printf("\n");
    }

    //zad2
    unsigned int rzedy;
    printf("Podaj liczbe rzedow trojkata: ");
    scanf("%u", &rzedy);
    for(int i=0; i<rzedy; i++)
    {
        for(int j=0; j<i+1; j++) printf("*");
        printf("\n");
    }

    //zad3
    unsigned int ilosc;
    printf("Podaj ilosc liczb (>=3): ");
    scanf("%u", &ilosc);
    for(int i=1; i<ilosc-1; i++)
    {
        for(int j=i+1; j<ilosc; j++)
        {
            for(int k=j+1; k<ilosc+1; k++)
            {
                printf("{%d, %d, %d}\t", i, j, k);
            }
        }
        printf("\n\n");
    }

    //zad4
    printf("Liczby 3-cyfrowe, ktorych cyfry ułożone są w kolejnosci malejacej: ");
    for(int i=1; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            for(int k=0; k<10; k++)
            {
                if(j<i && k<j) printf("%d%d%d\n", i, j, k);
            }
        }
    }

    //zad5
    unsigned int rzedy2;
    printf("Podaj n: ");
    scanf("%u", &rzedy2);
    for(int i=0; i<rzedy2; i++)
    {
        for(int j=1; j<rzedy2-i; j++) printf(" ");
        for(int j=0; j<2*i+1; j++) printf("*");
        printf("\n");
    }

    //zad6
    printf("Liczby pierwsze od 1 do 1000: 2, ");
    int flagaPierwsze;
    for(int i=1; i<500; i++)
    {
        flagaPierwsze=1;
        int potencjalnaPierwsza=2*i+1;
        for(int j=2; j<=sqrt(potencjalnaPierwsza); j++)
        {
            if(potencjalnaPierwsza%j==0) flagaPierwsze=0;
        }
        if(flagaPierwsze) printf("%d, ", potencjalnaPierwsza);
    }


    //zad7
    unsigned int liczba;
    short int q=1;
    printf("Podaj liczbe do sprawdzenia: ");
    scanf("%u", &liczba);
    for(int i=1; i<liczba && q==1; i++)
    {
        for(int j=1; j<liczba; j++)
        {
            if(j*j+i*i==liczba) 
            {
                printf("Tak: %d^2+%d^2=%d", i, j, liczba);
                q=0;
                break;
            }
        }
    }
    if(q) printf("Nie da się jej tak przedstawic");
    printf("\n");

    //zad8
    unsigned int zadanie=0;
    do
    {
        printf("Co chcesz zrobic:\n");
        printf("1 - sprawdzic czy liczba jest pierwsza\n");
        printf("2 - sprawdzic czy liczba jest suma dwoch kwadratow\n");
        printf("3 - policzyc sume cyfr liczby\n");
        printf("4 - zakonczyc dzialanie programu\n");
        scanf("%u", &zadanie);
        if(zadanie==1)
        {
            int flaga1=0;
            unsigned int zad1;
            printf("Podaj liczbe do sprawdzenia: ");
            scanf("%u", &zad1);
            for(int i=2; i<sqrt(zad1); i++)
            {
                if(zad1%i==0) 
                {
                    printf("nie jest to liczba pierwsza");
                    flaga1=1;
                    break;
                }
            }
            if(flaga1==0) printf("Jest to liczba pierwsza");
            printf("\n");
        }
        else if(zadanie==2)
        {
            
            unsigned int zad2;
            short int flaga2=1;
            printf("Podaj liczbe do sprawdzenia: ");
            scanf("%u", &zad2);
            for(int i=1; i<zad2 && flaga2==1; i++)
            {
                for(int j=1; j<zad2; j++)
                {
                    if(j*j+i*i==zad2) 
                    {
                        printf("Tak: %d^2+%d^2=%d", i, j, zad2);
                        flaga2=0;
                        break;
                    }
                }
            }
            if(flaga2) printf("Nie da się jej tak przedstawic");
            printf("\n");
        }
        else if(zadanie==3)
        {
            unsigned int zad3,suma3=0;
            printf("Podaj liczbe naturalna: ");
            scanf("%u", &zad3);
            while(zad3>0)
            {
                suma3+=zad3%10;
                zad3/=10;
            }
            printf("Suma cyfr: %u\n", suma3);
        } else if(zadanie!=4) printf("Nie ma takiego numeru!\n");
        
    } while (zadanie!=4);
    


    return 0;
}