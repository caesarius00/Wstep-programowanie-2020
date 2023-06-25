#include <stdio.h>

typedef struct
{
    int arr[100];
    int size;
}stackType;

int pop(stackType *stack)
{
    int toBeReturned=stack->arr[--stack->size];
    //aby usunac ze stosu, wystarczy ze zmniejsze ilosc jego elementow
    //wartosc nadpisze sie przy kolejnym wywolaniu push
    return toBeReturned;
}

void push(stackType *stack, int elem)
{
    if(stack->size<100)
    {
        stack->arr[stack->size]=elem;
        stack->size++;
        printf("Dodano na stos\n");
    }
    else printf("Stos jest pełny\n");
}

short int isEmpty(stackType *stack) //funkcja zwraca 1 jesli pusty
{
    if(stack->size) return 0;
    else return 1;
}

int top(stackType *stack)
{
   return stack->arr[stack->size-1];
}

int size(stackType *stack)
{
    return stack->size;
}


int main()
{
    int choice=1, element;
    stackType stack;
    stack.size=0;
    while(choice)
    {
        printf("1 - pop\n2 - push\n3 - top\n4 - isEmpty\n5 - size\n\n0 - wyjscie\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if(!isEmpty(&stack)) printf("Sciagnieto %d\n", pop(&stack));
            else printf("Stos jest pusty\n");
            break;
        case 2:
            printf("Podaj element do dodania: ");
            scanf("%d", &element);
            push(&stack, element);
            break;
        case 3:
            if(isEmpty(&stack)) printf("Stos jest pusty\n");
            else printf("wartosc z gory stosu: %d\n", top(&stack));
            break;
        case 4:
            if(isEmpty(&stack)) printf("Stos jest pusty\n");
            else printf("Stos nie jest pusty\n");
            break;
        case 5:
            printf("Rozmiar stosu: %d\n", size(&stack));
            break;
        
        default:
            break;
        }
    }
    return 0;
}