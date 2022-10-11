#include<stdio.h> 
void countSort(int arr[], int n);
int main()
{
	int n, i;
	printf("Enter size of array: ");
	scanf("%d", &n);	
	int arr[n];
	printf("Enter array: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	countSort(arr, n);
	printf("The Sorted array is : ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
return 0;
}

void countSort(int arr[], int n)
{
	int temp[n], max = arr[0], i;
	
	for (i = 1; i < n; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	int count[max + 1];
	for (i = 0; i <= max; i++)
	{
		count[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		count[arr[i]]++;
	}
	for (i = 1; i <= max; i++)
	{
		count[i] += count[i - 1];
	}
	for (i = n - 1; i >= 0; i--)
	{
		temp[--count[arr[i]]] = arr[i];
	}
	for (i = 0; i < n; i++)
	{
		arr[i] = temp[i];
	}
}
