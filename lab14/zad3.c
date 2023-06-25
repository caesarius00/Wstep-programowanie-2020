#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct
{
    int x;
    int y;
}PointType;


typedef struct elemkol
{
   PointType point;
   struct elemkol* nast;
} TElemKol;

typedef struct
{
   TElemKol* pierwszy;
   TElemKol* ostatni;
} TKolejka;

void init(TKolejka*);
bool isEmpty(TKolejka*);
bool enqueue(TKolejka*, int, int);
PointType dequeue(TKolejka*);
void show(TKolejka*);

int main()
{
   TKolejka kol;
   init(&kol);

   printf("Dodaje do kolejki 10 10\n");
   if (!enqueue(&kol, 10, 10)) 
      return 1;

   printf("Dodaje do kolejki 15 15\n");
   if (!enqueue(&kol, 15, 15)) 
      return 1;

   printf("Dodaje do kolejki 20 20\n");
   if (!enqueue(&kol, 20, 20)) 
      return 1;

    PointType zdjety=dequeue(&kol);
   printf("Zdejmuje z kolejki: (%d, %d)\n", zdjety.x, zdjety.y);

   printf("Dodaje do kolejki 15 15\n");
   if (!enqueue(&kol, 15, 15)) 
      return 1;

   while (!isEmpty(&kol))
   {
       zdjety=dequeue(&kol);
      printf("Zdejmuje z kolejki: (%d, %d)\n", zdjety.x, zdjety.y);
   }

   return 0;
}

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