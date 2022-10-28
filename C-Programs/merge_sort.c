/*
    In this program we will sort program using merge sorting algorithm.
*/

#include<stdio.h>
#include<stdlib.h>

void print_array(int *arr, int start, int end);
void merge_sort(int *arr, int start, int end);
void merge(int *arr, int start, int mid, int end);

// testing algorithm and output
int main(){

    int arr[] = {9,1,45,6,2,6,5};
    int len = sizeof(arr)/ sizeof(arr[0]);
    
    merge_sort(arr, 0, len - 1);
    print_array(arr,0, len - 1);
    // for linux otherwise it will show % at the end of terminal
    printf("\n");
    return 0;
}

// this will just divide array into two parts
void merge_sort(int *arr, int start, int end){
    if(start < end){
        int mid = start + (end - start)/2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

// I had added start and end parameter here because 
// in cause you want to print array at the middle of program
// start is index of first element and 
// end is index of last element
void print_array(int *arr, int start, int end){
    int len = end - start + 1;
    printf("\n");
    for(int i = start; i< len; i ++){
        printf(" %d", arr[i]);
    }
}

// start is index of first element 
// mid is the index of middle element and 
// end is index of last element
void merge(int *arr, int start, int mid, int end){
    // calculating the length of array on which we will work on this function
    int len = end - start + 1;

    // creating space for new array as per requirement
    int * merged = (int *) malloc(sizeof(int) * len);

    // indexing later used in this function
    int i1 = start, i2 = mid + 1,x = 0;

    while(i1 <= mid && i2 <= end){
        if(arr[i1] <= arr[i2]){
            merged[x++] = arr[i1++];
        }else{
            merged[x++] = arr[i2++];
        }
    }

    // adding left over elements on merged array
    // only one of these two loop will execute
    while(i1 <= mid){
        merged[x++] = arr[i1++];
    }
    while(i2 <= end){
        merged[x++] = arr[i2++];
    }

    // copying merged array in original array
    for(int i = 0, j = start; i < len; i++, j++){
        arr[j] = merged[i];
    }

    // freeing allocated memory
    free(merged);
}