//Write a program in C to print the Fibonacci Series using recursion.
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int i,int n){
    if(i <= n){
        return ;
    }
    else{
        return 1;
    }
}

void main(){
    int n;
    printf("Input number of terms for the Series (< 20) : ");
    scanf("%d",&n);
    fibonacci(1,n);
}