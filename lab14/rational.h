#ifndef RATIONAL_H
#define RATIONAL_H

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

#endif