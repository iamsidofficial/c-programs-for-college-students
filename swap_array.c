#include <stdio.h>

void swap(int arr1[], int arr[], int len);

int main(int argc, const char * argv[]) {
    
    int arr1[6] = {1, 2, 3, 4, 5, 6};
    int arr2[6] = {99, 88, 77, 66, 55, 44};
    
    swap(arr1, arr2, 6);
    
    return 0;
}

void swap(int arr1[], int arr2[], int len)
{
    int tmp; // create a tmp integer to stpre a value.
    
    for(int i = 0; i < len; i++)
    {
        tmp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = tmp;
    }
    
    printf("First Array after the swap:\n");
    //print arr1
    for(int i = 0; i < len; i++)
    {
        printf("%d ", arr1[i]);
    }
    
    printf("\n\nSecond Array after the swap:\n");
    //print arr2
    for(int i = 0; i < len; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");
}
