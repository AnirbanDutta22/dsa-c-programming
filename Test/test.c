#include <stdio.h>
#include <stdlib.h>
#define NULLVAL 0

void main(){
    int *p,*table;
    int size;
    printf("enter size\n");
    scanf("%d",&size);
    printf("\n");
    table = (int*)malloc(size*sizeof(int));
    if(table==NULLVAL){
        printf("No space available\n");
        exit(1);
    }
    printf("%d\n",table+size);
    printf("Address of first byte %d\n",table);
    printf("Input table values\n");

    for(p=table;p<table+size;p++){
        scanf("%d",&(*p));
    }

    for(p=table+size-1;p>=table;p--){
        printf("%d is stored at address %u\n",*p,p);
    }
}