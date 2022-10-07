#include <stdio.h>

int count = 0;
//function to print the array
void printarray(int arr[], int size)
{
    count++;
    int i,j;
    FILE *fptr;
    fptr = fopen("input.txt", "a");
    for(i=0; i<size; i++)
    {
        fprintf(fptr, "%d ",arr[i]);
    }
    fprintf(fptr, "\n");
    fclose(fptr);
}

//function to swap the variables
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//permutation function
void permutation(int *arr, int start, int end)
{
    if(start==end)
    {
        printarray(arr, end+1);
        return;
    }
    int i;
    for(i=start;i<=end;i++)
    {
        //swapping numbers
        swap((arr+i), (arr+start));
        //fixing one first digit
        //and calling permutation on
        //the rest of the digits
        permutation(arr, start+1, end);
        swap((arr+i), (arr+start));
    }
}

int main()
{
    //taking input to the array
    int size;
    printf("Enter the size of array\n");
    scanf("%d",&size);
    int i;
    int arr[size];
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    //calling permutation function
    permutation(arr, 0, size-1);
    printf("%d ", count);
    return 0;
}