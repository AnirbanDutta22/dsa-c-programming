#include <stdio.h>
#define MAX 10

void bsearch(int a[],int n,int search){
    int l=0,u=n-1,m,flag=0;
    while(l<=u){
        m=(l+u)/2;
        if(a[m]==search){
            flag = 1;
            break;
        }
        else{
            if(a[m] > search){ //for sorted array in descending order, a[m] < search
                u = m-1; 
            }
            else{
                l = m+1;
            }
        }
    }
    if(flag==0){
        printf("Element not found\n");
    }
    else{
        printf("Element found\n");
    }
}

void main(){
    int i,n,array[MAX],search_el;
    printf("Enter no. of elements\n");
    scanf("%d",&n);

    printf("Enter elements in ascending order");
    for(i=0;i<n;i++){
        printf("\nElement %d : ",i+1);
        scanf("%d",&array[i]);
    }

    printf("Enter the element you want to search\n");
    scanf("%d",&search_el);
    bsearch(array,n,search_el);
}