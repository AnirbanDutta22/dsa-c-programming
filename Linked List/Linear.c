#include <stdio.h>
#include <stdlib.h>

typedef struct Linear_Linked_List_Node
{
    int data;
    struct Linear_Linked_List_Node *next;
} node;

// function for creating an empty list
void createEmptyList(node **head)
{
    *head = NULL;
}
void insertAtBeginning(node **head)
{
    node *ptr;
    int el;
    ptr = (node *)malloc(sizeof(node));
    printf("Enter an element\n");
    scanf("%d", &el);
    ptr->data = el;
    if (*head == NULL)
    {
        ptr->next = NULL;
    }
    else
    {
        ptr->next = *head;
    }
    *head = ptr;
}
void insertAtEnd(node **head)
{
    node *ptr, *prev;
    int el;
    ptr = (node *)malloc(sizeof(node));
    printf("Enter an element\n");
    scanf("%d", &el);
    ptr->data = el;
    if (*head == NULL)
    {
        ptr->next = NULL;
        *head = ptr;
    }
    else
    {
        ptr->next = NULL;
        prev = *head;//for getting the 2nd last node
        while (prev->next != NULL)
        {
            prev = prev->next;
        }
        prev->next = ptr;
    }
}
node *search(node *head, int item)
{
    while (head != NULL && head->data != item)
    {
        head = head->next;
    }
    return head;
}
void insertAfter(node *head)
{
    node *ptr, *loc;
    int el, item;
    printf("Enter the element you want to insert the new element after : ");
    scanf("%d", &item);
    loc = search(head, item);
    if (loc == NULL)
    {
        printf("Element not found\n");
        return;
    }
    ptr = (node *)malloc(sizeof(node));
    printf("Enter an element\n");
    scanf("%d", &el);
    ptr->data = el;
    ptr->next = loc->next;
    loc->next = ptr;
}
void deleteFromBegin(node **head)
{
    node *ptr;
    if (*head == NULL)
    {
        printf("No elements found\n");
        return;
    }
    else
    {
        ptr = *head;
        *head = (*head)->next;
        printf("Deleted element is : %d\n", ptr->data);
        free(ptr);
    }
}
void deleteFromEnd(node **head)
{
    node *ptr, *prev;
    if (*head == NULL)
    {
        return;
    }
    else if ((*head)->next == NULL)
    {
        ptr = *head;
        *head = NULL;
        printf("Deleted element is : %d\n", ptr->data);
        free(ptr);
    }
    else
    {
        // keeping track of the previous node
        prev = *head;
        ptr = (*head)->next;
        while (ptr->next != NULL)
        {
            prev = ptr; // storing the previous node
            ptr = ptr->next;
        }
        prev->next = NULL;
        printf("Deleted element is : %d\n", ptr->data);
        free(ptr);
    }
}
void deleteAny(node **head)
{
    node *ptr, *prev;
    int item;
    ptr = *head;
    printf("Enter the element you want to delete");
    scanf("%d", &item);
    // searching the element and keeping track of the previous node
    while (ptr != NULL && ptr->data != item)
    {
        prev = ptr; // storing the previous node
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("Element not found\n");
        return;
    }
    // unlinking the node from the list
    prev->next = ptr->next;
    printf("Deleted element is : %d\n", ptr->data);
    free(ptr);
}
void deleteEntireList(node **head)
{
    node *ptr;
    if (*head == NULL)
    {
        printf("No elements found\n");
        return;
    }
    else
    {
        while (*head != NULL)
        {
            ptr = *head;
            *head = (*head)->next;
            free(ptr);
        }
        printf("All elements are deleted.\n");
    }
}
void traverseInOrder(node *head)
{
    if (head == NULL)
    {
        printf("No elements found\n");
        return;
    }
    else
    {
        printf("Elements are : ");
        while (head->next != NULL)
        {
            printf("%d\t", head->data);
            head = head->next;
        }
    }
}
void traverseInReverse(node *head)
{
    if (head == NULL)
    {
        printf("No elements found\n");
        return;
    }
    else
    {
        if(head->next != NULL)
            traverseInReverse(head->next); // using recursion
        printf("%d\t",head->data);
    }
}

void main()
{
    node *head;
    int c;
    createEmptyList(&head);
    printf("Enter ---\n1 to insert at beginning,\n2 to insert at the end,\n3 to insert after an element,\n4 to display in order,\n5 to display in reverse order,\n6 to delete from beginning,\n7 to delete from end,\n8 to delete any element,\n9 to delete the entire list,\n10 to exit\n--------------\n");
    while (1)
    {
        printf("Enter your choice\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            insertAtBeginning(&head);
            break;
        case 2:
            insertAtEnd(&head);
            break;
        case 3:
            insertAfter(head);
            break;
        case 4:
            traverseInOrder(head);
            break;
        case 5:
            traverseInReverse(head);
            break;
        case 6:
            deleteFromBegin(&head);
            break;
        case 7:
            deleteFromEnd(&head);
            break;
        case 8:
            deleteAny(&head);
            break;
        case 9:
            deleteEntireList(&head);
            break;
        case 10:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }
}