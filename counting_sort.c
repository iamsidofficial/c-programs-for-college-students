#include <stdio.h>
#include <stdlib.h>

int max_element(int array[], int size);

// counting sort: sorting in linear time
void counting_sort(int array[], int size)
{
    int max = max_element(array, size);

    int temp[max];          // a temporary array which will let us find and store the ranks of each element in the main array.
    int sorted_array[size]; // array to be returned with sorted elements

    for (int i = 0; i < max; i++)
    {
        temp[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        // counting each element
        temp[array[i]]++;
    }

    for (int i = 1; i < max; i++)
    {
        // finding and storing the rank of each element (number of elements lower than each element)
        temp[i] = temp[i] + temp[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        // placing each element in the respective index in sorted_array using the rank of each element
        sorted_array[temp[array[i]] - 1] = array[i];
    }

    for (int i = 0; i < size; i++)
    {
        // copying the sorted array into the original array
        array[i] = sorted_array[i];
    }
    // the sorted array can directly be returned here if the original array shouldnt be changed
}

// utility functions

int max_element(int array[], int size)
{
    int max = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

// main function
int main()
{
    // example
    int array[] = {5, 1, 2, 7, 12, 11, 8};
    // this sort is not feasible if the greatest element in the array is very big.
    // the greatest element in the array should stay low for direct counting sort to work properly without any memory issues.
    
    int size = sizeof(array) / sizeof(array[0]);
    counting_sort(array, size);

    print_array(array, size);
    return 0;
}
