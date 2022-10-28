#include <stdio.h>
#include<stdlib.h>

struct ARRAY{
    int A[10];
    int length;
    int size;
};

void reverse(struct ARRAY *arr){
    int b[arr->length];
    int j=0;
    for(int i=arr->length-1;i>=0;i--){
        b[j]=arr->A[i];
        j++;
    }
    for(int i=0;i<=arr->length-1;i++){
        arr->A[i]=b[i];
    }
}

void display(struct ARRAY arr){
    printf("\nElements are:\n");
    for(int i=0;i<arr.length;i++){
        printf("%d ",arr.A[i]);
    }
}


int main(){
    struct ARRAY arr={{3,4,6,5,4},5,10};
    reverse(&arr);
    display(arr);



    return 0;
}