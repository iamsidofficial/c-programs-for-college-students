// Inversion Pair using Merge Sort algorithm

#include <stdio.h>
#include <stdlib.h>

int Sort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid, int right);

int mergeSort(int arr[], int array_size)
{
	int* temp = (int*)malloc(sizeof(int) * array_size);
	return Sort(arr, temp, 0, array_size - 1);
}

int Sort(int arr[], int temp[], int left, int right)
{
	int mid, inv_count = 0;
	if (right > left) 
	{
		mid = (right + left) / 2;
		inv_count += Sort(arr, temp, left, mid);
		inv_count += Sort(arr, temp, mid + 1, right);
		inv_count += merge(arr, temp, left, mid + 1, right);
	}
	return inv_count;
}

int merge(int arr[], int temp[], int left, int mid, int right)
{
	int i, j, k;
	int inv_count = 0;

	i = left; // i is index for left subarray
	j = mid; // j is index for right subarray
	k = left; // k is index for resultant merged subarray
	while ((i <= mid - 1) && (j <= right)) 
	{
		if (arr[i] <= arr[j]) 
		{
			temp[k++] = arr[i++];
		}
		else 
		{
			temp[k++] = arr[j++];
			inv_count = inv_count + (mid - i);
		}
	}

	while (i <= mid - 1)
		temp[k++] = arr[i++];

	while (j <= right)
		temp[k++] = arr[j++];

	//Copy merged elements to original array
	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}

int main()
{
	int size,i;
	printf("Enter size of array:");
	scanf("%d",&size);
	int arr[size];
	printf("\nEnter elements of the array:");
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nNumber of inversions are %d \n", mergeSort(arr, size));
	getchar();
	return 0;
}
