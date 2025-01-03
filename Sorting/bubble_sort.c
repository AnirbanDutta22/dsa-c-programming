#include <stdio.h>
#define MAX 10

void bubble_sort(int a[],int n){
    int i,j,temp;

    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void main(){
    int i,n,array[MAX];
    printf("Enter no. of elements\n");
    scanf("%d",&n);

    printf("Enter elements in ascending order");
    for(i=0;i<n;i++){
        printf("\nElement %d : ",i+1);
        scanf("%d",&array[i]);
    }
    bubble_sort(array,n);
    printf("Sorted array : \n");
    for(i=0;i<n;i++){
        printf("%d\t",array[i]);
    }
}