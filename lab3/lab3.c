#include <stdio.h>
#include <math.h>

int main()
{
    //zad1
    printf("Liczby podzielne przez 5, które po podzieleniu przez 7 daja reszte 4: \n");
    int a=1;
    while(a<1001)
    {
        if(a%5==0 && a%7==4) printf("%d ", a);
        a++;
    
    }
    printf("\n");


    //zad2
    int n;
    printf("Podaj liczbe n: ");
    scanf("%d", &n);
    printf("Liczby podzielne przez 3, a mniejsze od n=%d: ", n);
    for(int i=1; i<n; i++)
    {
        if(i%3==0) printf("%d ", i);
    }
    printf("\n");

    //zad3
    int n2;
    int q=0;
    printf("Podaj liczbe n: ");
    scanf("%d", &n2);
    if(n2<2) printf("Nie jest to liczba pierwsza");
    else
    {  
        for(int i=2; i<=sqrt(n2); i++)
        {
            if(n2%i==0)
            {
                q++;
                printf("Nie jest to liczba pierwsza");
                break;
            }
        }
        if(q==0) printf("Jest to liczba pierwsza");
    }
    printf("\n");

    //zad4a
    /*int sum=0, i=1;
    do
    {
        sum+=i;
        printf("%d\n", sum);
        i+=2;
    } while (i<=100);*/

    //zad4b
    /*int sum=0, i=1;
    while(i<=100)
    {
        sum+=i;
        printf("%d\n", sum);
        i+=2;
    }*/

    //zad5a
    /*int i;
    printf("Podaj dodatnia liczbe calkowita\n");
    scanf("%d", &i);
    for(int j=i; j<=0; j=i)
    {
        printf("Podaj ponowanie dodatnia liczbe calkowita\n");
        scanf("%d", &i);

    }*/
    
    //zad5b
    /*int i;
    do
    {
        printf("Podaj dodatnia liczbe calkowita\n");
        scanf("%d", &i);
         
    } while (i<=0);*/

    //zad6
    unsigned int liczba;
    printf("Podaj liczbe naturalna: ");
    scanf("%u", &liczba);
    printf("Zapis binarny od tylu: ");
    while(liczba>0)
    {
        printf("%d", liczba%2);
        liczba=liczba/2;
    }
    printf("\n");
    
    //zad7
    unsigned int n3;
    unsigned int silnia=1;
    printf("Podaj liczbe n>0: ");
    scanf("%u", &n3);
    for(int i=n3;i>1;i--)
    {
        silnia*=i;
    }
    printf("%u! = %u", n3, silnia);
    printf("\n");
    

    //zad8
    double podstawa;
    unsigned int wykladnik;
    printf("Podaj podstawe i wykladnik: ");
    scanf("%lf%u", &podstawa, &wykladnik);
    double wynik=podstawa;
    for(int i=1; i<wykladnik;i++)
    {
        wynik*=podstawa;
    }
    printf("%lf^%u = %lf", podstawa, wykladnik, wynik);

    printf("\n");

    //zad9
    int n4=0;
    do
    {
        printf("Podaj liczbe: ");
        scanf("%d", &n4);
    } while (n4!=0);

    //zad10
    /*int ilosc=-1;
    double srednia, r, suma=0, najmniejsza, najwieksza;
    do
    {
        printf("Podaj liczbe do zbioru: ");
        scanf("%lf", &r);
        if(ilosc==-1)
        {
            najmniejsza=r;
            najwieksza=r;
        }else if(r!=0)
        {
            if(r>najwieksza) najwieksza=r;
            if(r<najmniejsza) najmniejsza=r;
        }
        suma=suma+r;
        ilosc++;

    } while (r!=0);
    srednia= suma/ilosc;
    printf("Suma: %lf\nSrednia: %lf\nWart. najmniejsza: %lf\nWart. najwieksza: %lf\n", suma, srednia, najmniejsza, najwieksza);
    printf("\n");
    */

    //zad11
    int ilosc=-1;
    double srednia, r, suma=0, najmniejsza, najwieksza, drNajwieksza=0;
    do
    {
        printf("Podaj liczbe do zbioru: ");
        scanf("%lf", &r);
        if(ilosc==-1)
        {
            najmniejsza=r;
            najwieksza=r;
        }else if(r!=0)
        {
            if(r>najwieksza) 
            {
                if(najwieksza>drNajwieksza) drNajwieksza=najwieksza;
                najwieksza=r;
            } else if(r>drNajwieksza) drNajwieksza=r;
            
            if(r<najmniejsza) najmniejsza=r;
        }
        suma=suma+r;
        ilosc++;

    } while (r!=0);
    srednia= suma/ilosc;
    printf("Suma: %lf\nSrednia: %lf\nWart. najmniejsza: %lf\nWart. najwieksza: %lf\nDruga najwieksza: %lf\n", suma, srednia, najmniejsza, najwieksza, drNajwieksza);
    printf("\n");
    
    //zad 12
    unsigned int n5, suma2=0;
    printf("Podaj liczbe naturalna: ");
    scanf("%u", &n5);
    while(n5>0)
    {
        suma2+=n5%10;
        n5/=10;
    }
    printf("Suma cyfr: %u\n", suma2);


    //zad13
    int cyfry[8], liczDzie=1;
    for(int i=0;i<8;i++)
    {
        printf("Podaj cyfrę liczby w systemie binarnym: ");
        scanf("%d", cyfry + i);
    }
    for(int i=0; i<8; i++)
    {
        if(i==0) liczDzie=cyfry[0];
        else liczDzie=liczDzie*2+cyfry[i];
    }
    printf("Ta liczba to: %d\n", liczDzie);

    //zad14
    int kd=1, kg, j, licz, w=1;
    printf("Podaj liczbe: ");
    scanf("%d", &licz);
    kg=licz;
    while(w)
    {
        if(kg-kd<=1) 
        {
            printf("nie ma pierwiastka naturalnego");
            w=0;
        }
        else
        {
            j=(kd+kg)/2;
            if(j*j==licz) 
            {
                w=0;
                printf("Pierwiastkiem jest %d", j);
            }
            else if(j*j>licz) kg=j;
            else if(j*j<licz) kd=j;
            
        }
        
    }

    return 0;
}