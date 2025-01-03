#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct stack_array
{
    int array[MAX], top;
} stack;

void init(stack *ptr)
{
    ptr->top = -1;
}
int isFull(stack *ptr)
{
    int full = 0;
    if (ptr->top == MAX - 1)
    {
        full = 1;
    }
    return full;
}
int isEmpty(stack *ptr)
{
    int emp = 0;
    if (ptr->top == -1)
    {
        emp = 1;
    }
    return emp;
}
void push(stack *ptr)
{
    if (isFull(ptr))
    {
        printf("Stack is Full\n");
        return;
    }
    ptr->top++;
    int el;
    printf("Enter an element\n");
    scanf("%d", &el);
    ptr->array[ptr->top] = el;
}
void pop(stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Empty\n");
        return;
    }
    int del_el;
    del_el = ptr->array[ptr->top];
    ptr->top--;
    printf("Deleted element is : %d\n", del_el);
}
void display(stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Empty\n");
        return;
    }
    int i;
    printf("Elemets in the array are : ");
    for (i = ptr->top; i >= 0; i--)
    {
        printf("%d\t", ptr->array[i]);
    }
}

void main()
{
    stack s;
    int x;
    init(&s);
    printf("Enter 1 for push,2 for pop,3 for display,4 for exit\n");
    while (1)
    {
        printf("Enter ur choice\n");
        scanf("%d", &x);

        switch (x)
        {
        case 1:
            push(&s);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            display(&s);
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong Choice\n");
        }
    }
}