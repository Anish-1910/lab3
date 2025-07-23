#include <stdio.h>
#include <stdlib.h>
int findmax(int a[], int n)
{
        int max = a[0];
        for(int i=0;i<n;i++)
        {
                if(max<a[i]) max = a[i];
        }
        return max;
}
void counting_sort(int a[], int n, int exp)
{
        int digit;
        int *count = (int *)calloc(10, sizeof(int));
        int *output = (int *)malloc(n * sizeof(int));
        for(int i=0;i<n;i++)
        {
                count[(a[i]/exp)%10]++;
        }
        for(int i=1;i<10;i++)
        {
                count[i]+=count[i-1];
        }
        for(int i=n-1;i>=0;i--)
        {
                digit = (a[i]/exp)%10;
                output[count[digit]-1] = a[i];
                count[digit]--;
        }
        for(int i=0;i<n;i++)
        {
                a[i] = output[i];
        }
        free(count);
        free(output);
}

void radix_sort(int a[], int n)
{
	int max = findmax(a, n);
	for(int exp=1;max/exp>0;exp*=10)
	{
		counting_sort(a, n, exp);
	}
}
