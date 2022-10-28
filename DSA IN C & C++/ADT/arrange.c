#include <stdio.h>
#include<stdlib.h>

struct ARRAY{
    int A[10];
    int length;
    int size;
};




void display(struct ARRAY arr){
    printf("\nElements are:\n");
    for(int i=0;i<arr.length;i++){
        printf("%d ",arr.A[i]);
    }
}


void arrng(struct ARRAY *arr){
    int i=0;
    int j=arr->length-1;
    while(i<j){
        while(arr->A[i]<0){
            i++;
        }
        while(arr->A[j]>=0){
            j--;
        }
        if(i<j){
            int temp=arr->A[i];
        arr->A[i]=arr->A[j];
        arr->A[j]=temp;

        }
        
    }
}

int main(){
    struct ARRAY arr={{-1,3,-5,6,5,-9,10},7,10};
    display(arr);
    arrng(&arr);
    display(arr);




    return 0;
}