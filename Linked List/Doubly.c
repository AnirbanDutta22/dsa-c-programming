#include <stdio.h>
#include <stdlib.h>
// #include <alloc.h>
typedef struct Doubly_Linked_List_Node
{
    int data;
    struct Doubly_Linked_List_Node *next, *prev;
} node;

// function for creating an empty list
void createEmptyList(node **head, node **tail)
{
    *head = NULL;
    *tail = NULL;
}
void insertAtBeginning(node **head, node **tail)
{
    node *ptr;
    int el;
    ptr = (node *)malloc(sizeof(node));
    printf("Enter an element\n");
    scanf("%d", &el);
    ptr->data = el;
    if (*head == NULL){
        ptr->next = ptr->prev = NULL;
        *head = *tail = ptr;
    }
    else{
        ptr->next = *head;
        ptr->prev = NULL;
        (ptr->next)->prev = ptr;
        *head = ptr;  
    }
}
void insertAtEnd(node **head, node **tail)
{
    node *ptr;
    int el;
    ptr = (node *)malloc(sizeof(node));
    printf("Enter an element\n");
    scanf("%d", &el);
    ptr->data = el;
    if (*head == NULL)
    {
        ptr->next = ptr->prev = NULL;
        *head = *tail = ptr;
    }
    else
    {
        ptr->next = NULL;
        ptr->prev = *tail;
        (*tail)->next = ptr;
        *tail = ptr;
    }
}
node *search(node *ptr, int el)
{
    while (ptr != NULL)
    {
        if (ptr->data == el)
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}
void insertAfter(node **head, node **tail)
{
    node *ptr, *loc;
    int el, item;
    printf("Enter the element you want to insert after\n");
    scanf("%d", &item);
    ptr = *head;
    loc = search(ptr, item);
    if (loc == NULL){
        printf("Element not found\n");
        return;
    }
    ptr = (node *)malloc(sizeof(node));
    printf("Enter an element\n");
    scanf("%d", &el);
    ptr->data = el;
    if (loc->next == NULL)
    {
        ptr->next = NULL;
        loc->next = ptr;
        ptr->prev = *tail;
        *tail = ptr;
    }
    else
    {
        ptr->prev = loc;
        ptr->next = *tail;
        (*tail)->prev = ptr;
        loc->next = ptr;
    }
}
void insertBefore(node **head) //not working
{
    node *ptr, *loc;
    int el, item;
    printf("Enter the element you want to insert before\n");
    scanf("%d", &item);
    ptr = *head;
    loc = search(ptr, item);
    if (loc == NULL){
        printf("Element not found\n");
        return;
    }
    ptr = (node *)malloc(sizeof(node));
    printf("Enter an element\n");
    scanf("%d", &el);
    ptr->data = el;
    if (loc->prev == NULL)
    {
        ptr->prev = NULL;
        loc->prev = ptr;
        ptr->next = *head;
        *head = ptr;
    }
    else
    {
        ptr->prev = loc->prev;
        ptr->next = loc;
        (loc->prev)->next = ptr;
        loc->prev = ptr;
    }
}
void traverseInOrder(node *head)
{
    if (head == NULL)
    {
        printf("No elements found\n");
    }
    else
    {
        printf("Elements are: ");
        while (head != NULL)
        {
            printf("%d\t", head->data);
            head = head->next;
        }
        printf("\n");
    }
}
void traverseReverse(node *tail)
{
    if (tail == NULL)
    {
        printf("No elements found\n");
    }
    else
    {
        printf("Elements are : ");
        while (tail != NULL)
        {
            printf("%d\t", tail->data);
            tail = tail->prev;
        }
        printf("\n");
    }
}
void deleteFromBegin(node **head, node **tail)
{
    node *ptr;
    if (*head == NULL)
        return;
    ptr = *head;
    if (*head == *tail)
        *head = *tail = NULL;
    else
    {
        (ptr->next)->prev = NULL;
        *head = ptr->next;
    }
    printf("Deleted Element is : %d\n", ptr->data);
    free(ptr);
}
void deleteFromEnd(node **head,node **tail){
    node *ptr;
    if (*head == NULL)
        return;
    ptr = *tail;
    if (*head == *tail)
        *head = *tail = NULL;
    else
    {
        (ptr->prev)->next = NULL;
        *tail = ptr->prev;
    }
    printf("Deleted Element is : %d\n", ptr->data);
    free(ptr);
}
void deleteAny(node **head,node **tail){
    node *ptr,*loc;
    int item;
    printf("Enter the element you want to delete\n");
    scanf("%d", &item);
    ptr = *head;
    loc = search(ptr, item);
    if (loc == NULL){
        printf("Element not found\n");
        return;
    }
    if (*head == *tail){
        *head = *tail = NULL;
    }
    else if(loc->prev==NULL){
        (loc->next)->prev = NULL;
        *head = loc->next;
        printf("Deleted Element is : %d\n", loc->data);
        free(loc);
    }
    else if(loc->next==NULL){
        (loc->prev)->next = NULL;
        *tail = loc->prev;
        printf("Deleted Element is : %d\n", loc->data);
        free(loc);
    }
    else{
        (loc->next)->prev=loc->prev;
        (loc->prev)->next=loc->next;
        printf("Deleted Element is : %d\n", loc->data);
        free(loc);
    }
}
void deleteEntireList(node **head,node **tail){
    node *ptr;
    printf("Deleted : ");
    while(*head!=NULL){
        ptr=*head;
        *head=(*head)->next;
        printf("%d\t",ptr->data);
        free(ptr);
    }
    *tail = NULL;
    printf("\nEntire list is deleted\n");
}
void main()
{
    node *head, *tail;
    int c;
    createEmptyList(&head, &tail);
    printf("Enter ---\n1 to insert at beginning,\n2 to insert at the end,\n3 to insert after an element,\n4 to insert before an element,\n5 display in order,\n6 to display in reverse order,\n7 to delete from beginning,\n8 to delete from end,\n9 to delete any element,\n10 to delete the entire list,\n11 to exit\n--------------\n");
    while (1)
    {
        printf("Enter your choice\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            insertAtBeginning(&head, &tail);
            break;
        case 2:
            insertAtEnd(&head, &tail);
            break;
        case 3:
            insertAfter(&head, &tail);
            break;
        case 4:
            insertBefore(&head);
            break;
        case 5:
            traverseInOrder(head);
            break;
        case 6:
            traverseReverse(tail);
            break;
        case 7:
            deleteFromBegin(&head, &tail);
            break;
        case 8:
            deleteFromEnd(&head, &tail);
            break;
        case 9: 
            deleteAny(&head,&tail);
            break;
        case 10: 
            deleteEntireList(&head,&tail);
            break;
        case 11:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }
}