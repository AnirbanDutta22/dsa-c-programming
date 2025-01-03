#include <stdio.h>
#define MAX 10

void lsearch(int a[],int n,int search){
    int i,flag=0;

    for(i=0;i<n;i++){
        if(search == a[i]){
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Element not found\n");
    }
    else{
        printf("Element found. Position:%d\n",i+1);
    }
}

void main(){
    int i,array[MAX],n,search_el;
    printf("Enter the number of elements\n");
    scanf("%d",&n);

    printf("Enter elements\n");
    for(i=0;i<n;i++){
        printf("Element %d : ",i+1);
        scanf("%d",&array[i]);
    }
    printf("Enter the element you want to search\n");
    scanf("%d",&search_el);

    lsearch(array,n,search_el);
}