#include <stdio.h>

typedef struct
{
    int nominator;
    int denominator;
}rationalNumb;

int NWD(int a, int b);
int NWW(int a, int b);
rationalNumb changeDenominator(rationalNumb liczba, int newDenominator);
rationalNumb shortening(rationalNumb liczba);
rationalNumb sum(rationalNumb liczba1, rationalNumb liczba2);
rationalNumb difference(rationalNumb liczba1, rationalNumb liczba2);
rationalNumb multiplication(rationalNumb liczba1, rationalNumb liczba2);
rationalNumb division(rationalNumb liczba1, rationalNumb liczba2);

int main()
{
    rationalNumb liczba1, liczba2, liczba3, liczba4, liczba5, result;
    //program zaklada, że jesli liczba jest ujemna, to znak zawiera się w liczniku

    //kazda liczbe przedstawiam jako licznik i mianownik
    liczba1.nominator=1, liczba1.denominator=2;
    liczba2.nominator=1, liczba2.denominator=3;
    liczba3.nominator=7, liczba3.denominator=2;
    liczba4.nominator=2, liczba4.denominator=3;
    liczba5.nominator=10, liczba5.denominator=3;
    result=difference(multiplication(sum(liczba1, liczba2), division(liczba3, liczba4)), liczba5);
    printf("%d/%d\n", result.nominator, result.denominator);
    return 0;
}

int NWD(int a, int b)
{
    if(a<0)
    {
        return NWD(a*(-1), b);
    }
    else
    {
        if(a>b) return NWD(a-b, b);
        else if(b>a) return NWD(a, b-a);
        else return a;
    }
    
}
int NWW(int a, int b)
{
    int originA=a, originB=b;
    while(a!=b)
    {
        if(b>a) a+=originA;
        else b+=originB;
    }
    return a;
}

rationalNumb changeDenominator(rationalNumb liczba, int newDenominator)
{
    liczba.nominator=liczba.nominator*newDenominator/liczba.denominator;
    liczba.denominator=newDenominator;
    return liczba;
}


rationalNumb shortening(rationalNumb liczba)
{
    int NWDresult=NWD(liczba.nominator, liczba.denominator);
    liczba.nominator/=NWDresult;
    liczba.denominator/=NWDresult;
    return liczba;
}

rationalNumb sum(rationalNumb liczba1, rationalNumb liczba2)
{
    rationalNumb result;
    liczba1=shortening(liczba1);
    liczba2=shortening(liczba2);
    int NWWresult=NWW(liczba1.denominator, liczba2.denominator);
    
    //zmiana licznika i mianownika, aby mozna bylo je dodac
    liczba1=changeDenominator(liczba1, NWWresult);
    liczba2=changeDenominator(liczba2, NWWresult);

    //obliczanie i zwracanie skroconej sumy
    result.nominator=liczba1.nominator+liczba2.nominator;
    result.denominator=NWWresult;
    return shortening(result);
}

rationalNumb difference(rationalNumb liczba1, rationalNumb liczba2)
{
    liczba1=shortening(liczba1);
    liczba2=shortening(liczba2);
    int NWWresult=NWW(liczba1.denominator, liczba2.denominator);
    rationalNumb result;
    liczba1=changeDenominator(liczba1, NWWresult);
    liczba2=changeDenominator(liczba2, NWWresult);
    result.nominator=liczba1.nominator-liczba2.nominator;
    result.denominator=NWWresult;
    return shortening(result);
}

rationalNumb multiplication(rationalNumb liczba1, rationalNumb liczba2)
{
    rationalNumb result;
    liczba1=shortening(liczba1);
    liczba2=shortening(liczba2);
    result.nominator=liczba1.nominator*liczba2.nominator;
    result.denominator=liczba1.denominator*liczba2.denominator;
    return shortening(result);
}

rationalNumb division(rationalNumb liczba1, rationalNumb liczba2)
{
    //korzystam z wlasnosci dzielenia jako mnozenia przez liczbe odwrotna
    rationalNumb temp;

    //przenosze znak do mianownika, aby pozniej znalazl sie znowu w liczniku
    if(liczba2.nominator<0)
    {
        liczba2.nominator*=(-1);
        liczba2.denominator*=(-1);
    }
    temp.nominator=liczba2.denominator;
    temp.denominator=liczba2.nominator;
    return multiplication(liczba1, temp);
}