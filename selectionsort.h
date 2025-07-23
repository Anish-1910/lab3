#include <stdio.h>
void selection_sort(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		int minind = i;
		for(int j=i+1; j<n;j++)
		{
			if(a[j] < a[minind])
			{
				minind = j;
			}
		}
		int temp = a[i];
		a[i] = a[minind];
		a[minind] = temp;
	}
}

