#ifndef QUEUE_H
#define QUEUE_H

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
PointType rmSecond(TKolejka*);
PointType dequeue(TKolejka*);
void show(TKolejka*);

#endif