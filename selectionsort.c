#include <stdio.h>
#include "selectionsort.h"
int main()
{
        int n;
        printf("Enter the number of elements in the array:");
        scanf("%d", &n);
        int a[n];
        printf("Enter the elements:\n");
        for(int i=0;i<n;i++)
        {
                scanf("%d", &a[i]);
        }
        printf("The entered array is:\n");
        for(int i=0;i<n;i++)
        {
                printf("%d  ", a[i]);
        }
        selection_sort(a, n);
        printf("\nThe sorted array is:\n");
        for(int i=0;i<n;i++)
        {
                printf("%d  ", a[i]);
        }
        return 0;
}

