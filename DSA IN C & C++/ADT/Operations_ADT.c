#include <stdio.h>
#include<stdlib.h>

struct ARRAY{
    int A[10];
    int length;
    int size;
};

void append(struct ARRAY *arr,int x){
    arr->A[arr->length]=x;
    arr->length++;
}

void display(struct ARRAY arr){
    printf("\nElements are:\n");
    for(int i=0;i<arr.length;i++){
        printf("%d ",arr.A[i]);
    }
}

void insert(struct ARRAY *arr,int index,int x)
{
    if(index>=0 && index<arr->length){
        for(int i=arr->length;i>index;i--){
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }
    
}

void delete(struct ARRAY *arr,int index){
    if(index>=0 && index<arr->length){
        for(int i=index;i<arr->length;i++){
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
        
    }
    
}

int main(){
    struct ARRAY arr={{3,4,6,5,4},5,10};
    display(arr);
    append(&arr,9);
    display(arr);
    insert(&arr,2,10);
    display(arr);
    delete(&arr,4);
    display(arr);






    return 0;
}