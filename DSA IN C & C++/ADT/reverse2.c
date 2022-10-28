#include <stdio.h>
#include<stdlib.h>

struct ARRAY{
    int A[10];
    int length;
    int size;
};



void reverse(struct ARRAY *arr){
   int i=0;
   int j=arr->length-1;
   while(i<j){
       int temp=arr->A[i];
       arr->A[i]=arr->A[j];
       arr->A[j]=temp;
       i++;
       j--;
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