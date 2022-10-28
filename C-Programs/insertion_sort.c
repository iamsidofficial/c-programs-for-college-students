/*
In this program, we will perform Insertion sort and 
The worst case time complexity is O(n^2) and 
Best case time complexity is O(n).
*/

#include<stdio.h>

void print_array(int *arr, int len);
void insertion_sort(int *arr, int len);

// testing algorithm and showing output
int main(){

    int arr[] = {1,8,6,2,9,4};
    int len = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr, len);
    print_array(arr, len);
    printf("\n");
    return 0;
}


// function to print array
void print_array(int *arr, int len){
    printf("\n");
    for(int i = 0; i< len; i++){
        printf(" %d",arr[i]);
    }
}

/// @brief sort given int array using insertion sorting algorithm
/// @param arr given array
/// @param len length of array
void insertion_sort(int *arr, int len){
    // j is counter for while loop and key is element of array that we will sort
    int j,key;

    // going through all the elements of array
    for(int i = 1; i<len; i++){
        j = i -1;
        key = arr[i];
        // insertion logic
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--; 
        }
        arr[j+1] = key;
    }
}