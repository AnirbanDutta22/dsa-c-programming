#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct circular_queue_array
{
    int a[MAX], front, rear;
} cqueue;

void init(cqueue *ptr){
    ptr->front=0;
    ptr->rear=0;
}
int isFull(cqueue *ptr)
{
    int full = 0;
    if ((ptr->rear+1)% MAX == ptr->front)
    {
        full = 1;
    }
    return full;
}
int isEmpty(cqueue *ptr)
{
    int emp = 0;
    if (ptr->rear == ptr->front)
    {
        emp = 1;
    }
    return emp;
}
void insert(cqueue *ptr)
{
    if (isFull(ptr))
    {
        printf("Queue is full\n");
        return;
    }
    int el;
    printf("Enter an element\n");
    scanf("%d", &el);
    ptr->a[ptr->rear] = el;
    ptr->rear=(ptr->rear+1)% MAX;
}
void del(cqueue *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue is empty\n");
        return;
    }
    int y;
    y = ptr->a[ptr->front];
    printf("Deleted element %d\n", y);
    ptr->front=(ptr->front+1)% MAX;
}
void display(cqueue *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue is empty\n");
        return;
    }
    int i=ptr->front;
    while (i!=ptr->rear)
    {
        printf("%d\t",ptr->a[i]);
        i=(i+1) % MAX;
    }
}

void main()
{
    int c;
    cqueue cq;
    init(&cq);
    printf("Enter 1 for insert,2 for delete,3 for display,4 for exit\n");
    while (1)
    {
        printf("Enter ur choice\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            insert(&cq);
            break;
        case 2:
            del(&cq);
            break;
        case 3:
            display(&cq);
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }
}