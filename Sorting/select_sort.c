#include <stdio.h>
#define MAX 10

void selectSort(int *a,int n){
    int k,loc,small,temp;
    for(int i=1;i<=(n-1);i++){
        small = a[i-1];
        loc = i-1;
        for(int j=i;j<=(n-1);j++){
            if(a[j] < small){
                small = a[j];
                loc = j;
            }
        }
        if(loc != (i-1)){
            temp = a[i-1];
            a[i-1] = a[loc];
            a[loc] = temp;
        }
    }
}

void main(){
    int n,a[MAX];
    printf("Enter the the number of elements you want to insert : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter element %d : ", i + 1);
        scanf("%d", &a[i]);
    }

    selectSort(a,n); //sorting method

    printf("Elements after sorting are : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",a[i]);
    }
}