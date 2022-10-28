#include <stdio.h>
#include<stdlib.h>

struct ARRAY{
    int A[10];
    int length;
    int size;
};

void insSORT(struct ARRAY *arr,int x){
    int i=arr->length-1;
    while(x<arr->A[i]){
       arr->A[i+1]=arr->A[i];
       i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

void display(struct ARRAY arr){
    printf("\nElements are:\n");
    for(int i=0;i<arr.length;i++){
        printf("%d ",arr.A[i]);
    }
}




int main(){
      struct ARRAY arr={{3,4,6,8,9},5,10};
        display(arr);
        insSORT(&arr,7);
          display(arr);




    return 0;
}