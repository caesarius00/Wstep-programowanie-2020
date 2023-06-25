#include <stdio.h>
#include <string.h>

int main()
{
    char str[251];
    printf("Podaj swoje motto (max 250 znakow): ");
    scanf("%[^\n]s", str);
    printf("Dlugosc motta: %d\n", (int)strlen(str));
    printf("Motto: \"%s\"\n", str);
    return 0;
}