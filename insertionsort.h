#include <stdio.h>
void insertion_sort(int a[], int n)
{
	for(int i=1;i<n;i++)
	{
		int key = a[i];
		int j = i-1;
		while(key<a[j] && j>=0)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}

