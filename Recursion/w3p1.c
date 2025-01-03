//Write a program in C to print the first 50 natural numbers using recursion.
#include <stdio.h>
#include <stdlib.h>

void printNum(int n){
    if(n <= 50){
        printf("%d\n",n);
        return printNum(n+1);
    }
    else{
        return;
    }
}

void main(){
    int num = 1;
    printNum(num);
}