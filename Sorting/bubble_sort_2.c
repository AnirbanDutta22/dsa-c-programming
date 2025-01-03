#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int bubbleSort(int *a, int n)
{
    int k = 1, flag = 1, temp, count = 0;

    while ((k < n) && (flag))
    {
        flag = 0;
        for (int i = 0; i < n - k; i++)
        {
            if (a[i] > a[i + 1])
            {
                flag = 1;
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                count++;
            }
        }
        k++;
    }
    if (count == 0)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

void main()
{
    int n, a[MAX], result;
    printf("Enter the the number of elements you want to insert : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter element %d : ", i + 1);
        scanf("%d", &a[i]);
    }

    result = bubbleSort(a, n); // sorting method

    if (result == 1)
    {
        printf("Array is already sorted\n");
    }
    else
    {
        printf("Elements after sorting are : ");
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}