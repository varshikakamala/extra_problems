#include<stdio.h>
#include<stdlib.h>
void max_subarray(int *a, int n)
{
	int i,curr_sum = 0, max_sum = 0, firstpos=0, lastpos=0,initial_pos;
	max_sum = a[0];
	initial_pos = 0;
	for (i = 0; i < n; i++)
	{
		curr_sum += a[i];
		if (curr_sum < 0 || curr_sum<max_sum)
		{
			curr_sum = 0;
			initial_pos = i + 1;
		}
		if (curr_sum > max_sum)
		{
			max_sum = curr_sum;
			firstpos = initial_pos;
			lastpos = i;
		}
	}
	printf("\nmaximum sum is %d", max_sum);
	print("\nthe sub array is");
	for (i = firstpos; i < lastpos; i++)
	{
		printf("%d", a[i]);
	}
}
void main()
{
	int *arr, length = 0, i = 0;
	printf("\nred the length of array"); 
	scanf("%d", &length);
	arr = (int *)malloc(length*sizeof(int));
	printf("\nread the elements of array");
	for (i = 0; i < length; i++)
	{
		scanf("%d", &arr[i]);
	}
	max_subarray(arr, length);
}