#include "queue.h"

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void init(TKolejka *kol)
{
   kol->pierwszy = NULL;
   kol->ostatni = NULL;
}

bool isEmpty(TKolejka* kol)
{
   return (kol->pierwszy==NULL);
}

bool enqueue(TKolejka* kol, int valX, int valY)
{
   TElemKol* nowy = malloc(sizeof(TElemKol));
   if (nowy == NULL)
      return false;
   nowy->point.x = valX;
   nowy->point.y = valY;
   nowy->nast = NULL;
   if (kol->pierwszy == NULL)
   {
      kol->pierwszy = nowy;
      kol->ostatni = nowy;
   } else
   {
      kol->ostatni->nast = nowy;
      kol->ostatni = nowy;
   }
   return true;
}

PointType dequeue(TKolejka* kol)
{
   if (isEmpty(kol))
   {
       printf("Kolejka jest pusta");
       PointType ret;
       ret.x=-1;
       ret.y=-1;
       return ret;
   }
   TElemKol* usun = kol->pierwszy;
   kol->pierwszy = kol->pierwszy->nast;
   PointType retval = usun->point;
   free(usun);
   return retval;
}

PointType rmSecond(TKolejka* kol)
{
    if(isEmpty(kol) || kol->pierwszy->nast==NULL)
    {
        printf("Kolejka jest pusta");
        PointType ret;
        ret.x=-1;
        ret.y=-1;
        return ret;
    }
    TElemKol* usun=kol->pierwszy->nast;
    kol->pierwszy->nast=kol->pierwszy->nast->nast;
    PointType retval=usun->point;
    free(usun);
    return retval;
}

void show(TKolejka* kol)
{
   TElemKol* elem = kol->pierwszy;
   printf("Zawartosc kolejki: ");
   while (elem!=NULL)
   {
       PointType value=elem->point;
      printf("(%d, %d)", value.x, value.y);
      elem = elem->nast;
   }
   printf("\n");
}

