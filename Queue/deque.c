#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct deque_array
{
    int a[MAX], front, rear;
} deque;

int take_input(){
    int el;
    printf("Enter an element\n");
    scanf("%d", &el);
    return el;
}
void del_el(int deleted){
    printf("Deleted element : %d\n",deleted);
}
void init(deque *ptr)
{
    ptr->front = -1;
    ptr->rear = -1;
}
int isFull(deque *ptr)
{
    int full = 0;
    if (ptr->rear == MAX - 1)
    {
        full = 1;
    }
    return full;
}
int isEmpty(deque *ptr)
{
    int emp = 0;
    if (ptr->rear == ptr->front)
    {
        emp = 1;
    }
    return emp;
}
void insert_rear(deque *ptr)
{
    if (isFull(ptr))
    {
        printf("Queue is full\n");
        return;
    }
    int el;
    el = take_input();
    ptr->rear++;
    ptr->a[ptr->rear] = el;
}
void insert_front(deque *ptr)
{
    if (ptr->front == -1)
    {
        printf("Queue is Full\n");
    }
    else
    {
        int el;
        el = take_input();
        ptr->a[ptr->front] = el;
        ptr->front--;
    }
}
void del_front(deque *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue is empty\n");
        return;
    }
    int y;
    ptr->front++;
    y = ptr->a[ptr->front];
    del_el(y);
}
void del_rear(deque *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue is empty\n");
        return;
    }
    int y;
    y = ptr->a[ptr->rear];
    del_el(y);
    ptr->rear--;
}
void display(deque *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue is empty\n");
        return;
    }
    int i;
    for (i = ptr->front+1; i <= ptr->rear; i++)
    {
        printf("%d\t", ptr->a[i]);
    }
}

void main()
{
    int c;
    deque dq;
    init(&dq);
    printf("Enter 1 for insert_rear,2 for del_front,3 for insert_front,4 for del_rear,5 for display,6 for exit\n");
    while (1)
    {
        printf("Enter ur choice\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            insert_rear(&dq);
            break;
        case 2:
            del_front(&dq);
            break;
        case 3:
            insert_front(&dq);
            break;
        case 4:
            del_rear(&dq);
            break;
        case 5:
            display(&dq);
            break;
        case 6:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }
}