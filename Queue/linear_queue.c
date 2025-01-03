#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct queue_array
{
    int a[MAX], front, rear;
} queue;

void init(queue *ptr){
    ptr->front=-1;
    ptr->rear=-1;
}
int isFull(queue *ptr)
{
    int full = 0;
    if (ptr->rear == MAX - 1)
    {
        full = 1;
    }
    return full;
}
int isEmpty(queue *ptr)
{
    int emp = 0;
    if (ptr->rear == ptr->front)
    {
        emp = 1;
    }
    return emp;
}
void insert(queue *ptr)
{
    if (isFull(ptr))
    {
        printf("Queue is full\n");
        return;
    }
    int el;
    printf("Enter an element\n");
    scanf("%d", &el);
    ptr->rear++;
    ptr->a[ptr->rear] = el;
}
void del(queue *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue is empty\n");
        return;
    }
    int y;
    ptr->front++;
    y = ptr->a[ptr->front];
    printf("Deleted element %d\n", y);
}
void display(queue *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue is empty\n");
        return;
    }
    int i;
    for (i = ptr->front + 1; i <= ptr->rear; i++)
    {
        printf("%d\t", ptr->a[i]);
    }
}

void main()
{
    int c;
    queue q;
    init(&q);
    printf("Enter 1 for insert,2 for delete,3 for display,4 for exit\n");
    while (1)
    {
        printf("Enter ur choice\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            insert(&q);
            break;
        case 2:
            del(&q);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }
}