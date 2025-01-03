#include <stdlib.h>
#include <stdio.h>

typedef struct Linear_Linked_List_Node{
    int data;
    struct Linear_Linked_List_Node *next;
}node;

void createEmptyList(node **head){
    *head = NULL;
}
void insertAtBeginning(node **head){
    node *ptr;
    int el;
    ptr=(node *)malloc(sizeof(node));
    printf("Enter an element : ");
    scanf("%d",&el);
    ptr->data = el;
    if(*head == NULL){
        ptr->next = NULL;
    }
    else{
        ptr->next = *head;
    }
    *head = ptr;
}
void insertAtEnd(node **head){
    node *ptr,*prev;
    int el;
    ptr=(node *)malloc(sizeof(node));
    printf("Enter an element : ");
    scanf("%d",&el);
    ptr->data = el;
    if(*head == NULL){
        ptr->next = NULL;
        *head = ptr;
    }
    else{
        ptr->next = NULL;
        prev = *head;
        while(prev->next != NULL){
            prev = prev->next;
        }
        prev->next = ptr;
    }
}
node* search(node *ptr,int item){
    
}
void insertAfter(node **head){
    node *ptr,*loc;
    int el,item;
    printf("Enter the element you want to insert new element after : ");
    scanf("%d",&item);
    loc = search(,item);
    ptr=(node *)malloc(sizeof(node));
    printf("Enter an element : ");
    scanf("%d",&el);
    ptr->data = el;
}
void main()
{
    node *head;
    int c;
    createEmptyList(&head);
    printf("Enter ---\n1 to insert at beginning,\n2 to insert at the end,\n3 to insert after an element,\n4 to insert before an element,\n5 display in order,\n6 to display in reverse order,\n7 to delete from beginning,\n8 to delete from end,\n9 to delete any element,\n10 to delete the entire list,\n11 to exit\n--------------\n");
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
