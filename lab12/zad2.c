#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char name[12];
    float radius;
    float volume;
    float mass;
    float density;
    float surfaceGravity;
    char typeOfObject[25];
    char shape[10];
}solar;


int main()
{
    int count=0, ctr, flag=0, j=0, end=0;
    char temp[20];
    float avgVolume=0;
    FILE *fptr;
    fptr=fopen("12_solar.txt", "r");
    if(fptr!=NULL)
    {
        char var[15];
        int i=0;//ilosc spacji, ktore ominela funkcja fgetc
        do
        {
            ctr=fgetc(fptr);
            if(isspace(ctr)) i++; //jesli ctr wczytal spacje
            if(ctr=='\n') 
            {
                i=0;
                j=0;
                flag=1;
                strcpy(var, " "); //czyszczenie lancucha var
                end=0;
            }
            else if(i==2 && flag) //jesli jest to zmienna dotyczaca objetosci
            {
                if(ctr==',')
                {
                    strcat(var, ".");
                }
                else
                {
                    var[j]=ctr;
                    var[j+1]='\0';
                }
                j++;
                
            }
            else if(i==3 && !end) //po zakonczeniu zmiennej objetosci
            {
                end++;
            }
            else if(i==7 && ctr=='u')
            {
                avgVolume+=atof(var);
                count++;
            }
        } while (ctr!=EOF);
        avgVolume/=count;
        printf("Srednia wynosi: %d - %f", count,avgVolume);
    }
    else printf("Blad otwarcia pliku\n");
    
    return 0;
}