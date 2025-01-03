#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct stack_string
{
    char charArray[MAX];
    int top;
} stack;

static int i = 0;
static int flag = 0;

void push(stack *ptr, char *str_ptr)
{
    if (flag == 0)
    {
        for (; str_ptr[i] != '\0'; i++)
        {
            if (str_ptr[i] == '(' || str_ptr[i] == '{' || str_ptr[i] == '[')
            {
                ptr->top++;
                ptr->charArray[ptr->top] = str_ptr[i];
            }
            else
            {
                printf("All opening bracies are pushed\n");
                flag = 1;
                break;
            }
        }
    }
    else{
        printf("All opening bracies are pushed\n");
    }
}
// int pop(stack *ptr)
// {
//     int pop_str;
//     pop_str = ptr->charArray[ptr->top];
//     ptr->top--;
//     return pop_str;
// }
void match(stack *ptr, char *str_ptr)
{
    int pop_str,f=0;
    while (str_ptr[i] != '\0')
    {
        pop_str = ptr->charArray[ptr->top];
        ptr->top--;
        if ((pop_str == '(' && str_ptr[i] == ')') || (pop_str == '{' && str_ptr[i] == '}') || (pop_str == '[' && str_ptr[i] == ']'))
        {
            f=1;
            i++;
            continue;
        }
        else
        {
            f=0;
            printf("Wrong Match\n");
            break;
        }
    }
    if(f==1){
    printf("Right Match\n");
    }
}

void display(stack ptr)
{
    for (int i = ptr.top; i >= 0; i--)
    {
        printf("%c\t", ptr.charArray[i]);
    }
}

void main()
{
    stack s;
    char str[MAX];
    int x;
    s.top = -1;
    printf("Enter the string\n");
    scanf("%s", str);
    while (1)
    {
        printf("Enter 1 for push,2 for pop,3 for display,4 for exit\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            push(&s, str);
            break;
        case 2:
            match(&s, str);
            break;
        case 3:
            display(s);
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong Choice\n");
        }
    }
}