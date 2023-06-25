#include <stdio.h>

int fileSum(char *src)
{
    int sum=0, number;
    FILE *fptr;
    fptr=fopen(src, "r");
    while(fscanf(fptr, "%d", &number)==1) sum+=number;
    fclose(fptr);
    return sum;
}

int main()
{
    printf("Suma liczb z pliku wynosi %d", fileSum("zrodlo.txt"));
    return 0;
}