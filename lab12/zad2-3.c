#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char name[20];
    float radius;
    float volume;
    float mass;
    float density;
    float surfaceGravity;
    char typeOfObject[30];
    char shape[30];
}solar;

void changeSemiToDot();

int main()	
{
    solar fromFile[67]; //obiektow jest 66 + 1 na EOF
    changeSemiToDot();
    char ctr, temp[30];
    int counter=0;
    FILE *solarFile;
    solarFile=fopen("12_solar.txt", "r");
    while((ctr=fgetc(solarFile))!='\n'); //pomijam pierwsza linie

    //pobieranie i zapisywanie wartosci do pliku
    while(fscanf(solarFile, "%s", fromFile[counter].name)!=EOF)
    {
        //zapisywanie wartosci liczbowych
        for(int i=0; i<5; i++)
        {
            fscanf(solarFile, "%s", temp);
            //jesli wartosc jest nieznana, to objetosc oznaczam jako zero
            //te obiekty nie beda liczone do sredniej ze wzgledu na brak danych
            if(strstr(temp, "unknown")!=NULL)
            {
                switch (i)
                {
                case 0:
                    fromFile[counter].radius=0;
                    break; 
                case 1:
                    fromFile[counter].volume=0;
                    break; 
                case 2:
                    fromFile[counter].mass=0;
                    break; 
                case 3:
                    fromFile[counter].density=0;
                    break; 
                case 4:
                    fromFile[counter].surfaceGravity=0;
                    break;
                }
            }
            else
            {
                switch (i)
                {
                case 0:
                    fromFile[counter].radius=atof(temp);
                    break; 
                case 1:
                    fromFile[counter].volume=atof(temp);
                    break; 
                case 2:
                    fromFile[counter].mass=atof(temp);
                    break; 
                case 3:
                    fromFile[counter].density=atof(temp);
                    break; 
                case 4:
                    fromFile[counter].surfaceGravity=atof(temp);
                    break;
                }
            }
            
        }
        fscanf(solarFile, "%s", fromFile[counter].typeOfObject);
        fscanf(solarFile, "%s", fromFile[counter++].shape);

    }
    fclose(solarFile);

    //zad2
    //program liczy srednia objetosc obiektow o nieznanym ksztalcie i znanej objetosci
    float avgSum=0;
    int numberOfObjects=0;
    for(int i=0; i<67; i++)
    {
        if(strstr(fromFile[i].shape, "unknown")!=NULL && fromFile[i].volume)
        {
            avgSum+=fromFile[i].volume;
            numberOfObjects++;
        }
    }
    printf("Srednia %d takich obiektow wynosi %f", numberOfObjects, avgSum/numberOfObjects);

    //zad3
    //program zapisuje do pliku planets.txt informacje o planetach (nie karlowatych)
    FILE *planetsFile;
    planetsFile=fopen("planets.txt", "w");
    fprintf(planetsFile, "Body	radius(km)	Volume(10^9km^3)	Mass(10^21kg)	Density(g/cm^3)	Surface_gravity(m/s^2)	Type_of_object	Shape	\n");
    for(int i=0; i<67; i++)
    {
        if(strstr(fromFile[i].typeOfObject, "Planet")!=NULL)
        {
            fprintf(planetsFile, "%s %f %f %f %f %f %s %s\n", fromFile[i].name, fromFile[i].radius, fromFile[i].volume, fromFile[i].mass, fromFile[i].density, fromFile[i].surfaceGravity, fromFile[i].typeOfObject, fromFile[i].shape);
        }
    }
    fclose(planetsFile);
    return 0;
}

//wyrzucilem do osobnej funkcji po prostu dla czytelnosci
void changeSemiToDot()
{
    FILE *solarFile;
    solarFile=fopen("12_solar.txt", "r+");
    char ctr, toReplace=',', replaceWith='.';
    if(solarFile==NULL) printf("Blad otwarcia podczas zamiany\n");
    while((ctr=fgetc(solarFile))!=EOF)    //pobieraj kazdy znak do konca pliku
    {
        if(ctr==toReplace)              //czy jest to znak ktory chcemy zastapic ( , )
        {
            fseek(solarFile, ftell(solarFile)-1, SEEK_SET); //cofnij sie o 1 znak
            fprintf(solarFile, "%c", replaceWith);          //zamien w tym miejscu znak na .
        }
    }
    fclose(solarFile);
}