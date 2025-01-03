#include <stdio.h>
#define MAX 10

void insertionSort(int el,int *a,int i){
    static int j=0;
    j = i-1;
    while(el<a[j] && j>=0){
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=el;
}

void main(){
    int i,n,array[MAX],el;
    printf("Enter no. of elements\n");
    scanf("%d",&n);

    for(i=0;i<n;i++){                   //insertion sort 
        printf("Enter an element\n");
        scanf("%d",&el);
        insertionSort(el,array,i);       
    }
    printf("Sorted array\n");
    for(i=0;i<n;i++){
        printf("%d\t",array[i]);
    }
}