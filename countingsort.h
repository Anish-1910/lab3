#include <stdio.h>
#include <stdlib.h>
int findmax(int a[], int n)
{
	int max = a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max = a[i];
		}
	}
	return max;
}
int findmin(int a[], int n)
{
	int min = a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]<min) min = a[i];
	}
	return min;
}
void counting_sort(int a[], int n)
{
	int max = findmax(a, n);
	int min = findmin(a, n);
	int range = max-min+1;
	int *count = (int *)calloc(range, sizeof(int));
	int *output = (int *)malloc(n * sizeof(int));
	for(int i=0;i<n;i++)
	{
		count[a[i]-min]++;
	}
	for(int i=1;i<range;i++)
	{
		count[i]+=count[i-1];
	}
	for(int i=n-1;i>=0;i--)
	{
		output[count[a[i]-min]-1] = a[i];
		count[a[i]-min]--;
	}
	for(int i=0;i<n;i++)
	{
		a[i] = output[i];
	}
	free(count);
	free(output);
}

