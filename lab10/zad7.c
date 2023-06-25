#include <stdio.h>
#include <string.h>

void usunSpacje(char *str, int size)
{
    while(str[size-1]==' ')
    {
        str[size-1]='\0';
        size--;
    }
    while(str[0]==' ')
    {
        for(int i=0; i<size; i++)
        {
            str[i]=str[i+1];
        }
    }

}

int main()
{
    char str[]="   testowe zdanie     ";
    usunSpacje(str, strlen(str));
    printf("%s.", str);
    return 0;
}