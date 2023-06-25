#include "queue.h"

int main()
{
    /*pozycje na szachownicy
    y
x=  0   1   2   3   4   5   6   7
    1   
    2
    3
    4
    5
    6
    7
    */
   for(int k=0; k<8; k++)
   {
       for(int l=0; l<8; l++)
       {
            TKolejka Q;
            init(&Q);

            int chessboard[8][8];
            for(int i=0; i<8; i++)
                for(int j=0; j<8; j++)
                    chessboard[i][j]=-1;

            PointType p;
            p.x=k;
            p.y=l;
            enqueue(&Q, p.x, p.y);
            chessboard[p.x][p.y]=0;
            while(!isEmpty(&Q))
            {
                p=dequeue(&Q);

                //zmiana pozycji x
                for(int i=-2; i<3; i++)
                {
                    //zmiana pozycji y
                    for(int j=-2; j<3; j++)
                    {
                        //sprawdzam, czy nie wychodzi poza szachownice
                        if(p.x+i>0 && p.x+i<8 && p.y+j>0 && p.y+j<8)
                        {
                            PointType s;
                            s.x=p.x+i;
                            s.y=p.y+j;
                            if(chessboard[s.x][s.y]==-1)
                            {
                                chessboard[s.x][s.y]=chessboard[p.x][p.y]+1;
                                enqueue(&Q, s.x, s.y);
                            }
                        }
                    }
                }
            }
            int count=0;
            printf("Pozycja poczatkowa %d %d: \nWartosci tablicy: \n", k, l);
            for(int i=0; i<8; i++)
            {
                for(int j=0; j<8; j++)
                {
                    if(chessboard[i][j]==-1) count++;
                    else printf("%d; ",chessboard[i][j]);
                }
            }
            printf("\nOraz nieodwiedzone %d\n",count);
            //free(&Q);
       }
   }
    return 0;
}