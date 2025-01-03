#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef enum
{
    false,
    true
} boolean;


void partitionArray(int a[], int beg, int end, int *loc)
{
    int left, right, temp;
    boolean done;
    *loc = left = beg;
    right = end;
    done = false;
    while (!done)
    {
        // Scanning from left
        while ((a[*loc] <= a[right]) && (*loc != right))
        {
            right--;
        }
        if (*loc == right)
        {
            done = true;
        }
        else if (a[*loc] > a[right])
        {
            temp = a[*loc];
            a[*loc] = a[right];
            a[right] = temp;
            *loc = right;
        }
        if (!done)
        {
            //Scanning from right
            while ((a[*loc] >= a[left]) && (*loc != left))
            {
                left++;
            }
            if (*loc == left)
            {
                done = true;
            }
            else if (a[*loc] < a[left])
            {
                temp = a[*loc];
                a[*loc] = a[left];
                a[left] = temp;
                *loc = left;
            }
        }
    }
}
void quickSortRecursive(int a[], int lb, int ub)
{
    int loc;
    if (lb < ub)
    {
        partitionArray(a, lb, ub, &loc);
        quickSortRecursive(a, lb, loc - 1);
        quickSortRecursive(a, loc + 1, ub);
    }
}
void main()
{
    int i, n, a[MAX];
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    if (n > MAX)
    {
        printf("\nInput size of array is greater than declared size.\n");
        exit(1);
    }
    printf("Enter the elements of array --\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quickSortRecursive(a, 0, n - 1);
    printf("Elements after sorting : \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}