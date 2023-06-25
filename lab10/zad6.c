#define SIZE sizeof(str1)/sizeof(str1[0])
#include <stdio.h>
#include <string.h>

int countAppear(char *str1, char *str2, int firstSize)
{
    int appear=0;
    char *ptr;
    for(int j=0; j<strlen(str2)/strlen(str1); j++)
    {
        ptr=strstr(str2, str1);
        if(ptr!=NULL)
        {
            appear++;
            ptr="";
        }
        else break;
    }
    return appear;
}

int main()
{
    char str1[]="test", str2[]="ile wystepuje test";
    printf("str1 znajduje sie w str2 %d razy", countAppear(str1, str2, SIZE));
    return 0;
}