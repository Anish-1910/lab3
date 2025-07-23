#include <stdio.h>
#include "radixsort.h"
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
                printf("%d ", a[i]);
        }
        radix_sort(a, n);
        printf("\nThe sorted array is:\n");
        for(int i=0;i<n;i++)
        {
                printf("%d  ", a[i]);
        }
        return 0;
}

