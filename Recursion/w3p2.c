//Write a program in C to calculate the sum of numbers from 1 to n using recursion.
#include <stdio.h>
#include <stdlib.h>

int sumFun(int n){
    if(n > 0){
        return n + sumFun(n-1);
    }
    else{
        return n;
    }
}

void main(){
    int n;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    printf("%d",sumFun(n));
}