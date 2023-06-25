#include <stdio.h>

int main()
{

    //tak wiem, strasznie przekombinowane
    int tab1[10]={1,4,3,5,6,7,6,5,14,65}, tab2[10]={1,45,32,76,34,6,34,23,15,13}, tab3[10]={34,87,0,90,45,3,72,25,62,14}, i, max, max2, min;
    printf("Podaj i: ");
    scanf("%d", &i);
    if(tab1[i] >= tab2[i] && tab1[i] >= tab3[i]) max=tab1[i];
    else if(tab2[i] >= tab1[i] && tab2[i] >= tab3[i]) max=tab2[i];
    else if(tab3[i] >= tab2[i] && tab3[i] >= tab1[i]) max=tab3[i];


    if(tab1[i]<max)
    {
        if(tab1[i] >= tab2[i] || tab1[i] >= tab3[i])
        {
            max2=tab1[i];
        }
    }
    if(tab2[i]<max)
    {
        if(tab2[i] >= tab1[i] || tab2[i] >= tab3[i])
        {
            max2=tab2[i];
        }
    }
    if(tab3[i]<max)
    {
        if(tab3[i] >= tab2[i] || tab3[i] >= tab1[i])
        {
            max2=tab3[i];
        }
    }

    if(tab1[i]<=tab2[i] && tab1[i]<= tab3[i]) min=tab1[i];
    else if(tab2[i]<=tab1[i] && tab2[i]<= tab3[i]) min=tab2[i];
    else if(tab3[i]<=tab1[i] && tab3[i]<= tab2[i]) min=tab3[i];

    tab1[i]=max;
    if(tab1[i]<=tab2[i] && tab1[i]<= tab3[i]) min=tab1[i];
    tab2[i]=max2;
    tab3[i]=min;
    printf("%d %d %d", tab1[i], tab2[i], tab3[i]);

    return 0;
}