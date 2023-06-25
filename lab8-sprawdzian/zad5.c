#include <stdio.h>
#define SIZE 10

int main()
{
    int tab[SIZE]={1,2,3,4,5,6,7,8,9,10}, temp, temp2;
    for(int i=SIZE-1; i>=0; i--)
    {
        if(i==SIZE-1) 
        {
            temp=tab[i-1];
            tab[i-1]=tab[i];
        }
        else if(i==0) tab[SIZE-1]=temp;
        else 
        {
            temp2=tab[i-1];
            tab[i-1]=temp;
            temp=temp2;
        }
    }
    for(int i=0; i<SIZE; i++) printf("%d, ", tab[i]);
    return 0;
}