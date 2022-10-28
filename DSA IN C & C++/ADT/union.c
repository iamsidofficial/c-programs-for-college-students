#include <stdio.h>
#include <stdlib.h>

struct ARRAY{
    int A[10];
    int length;
    int size;
};

void display(struct ARRAY arr)
{
 int i;
 printf("\nElements are\n");
 for(i=0;i<arr.length;i++)
 printf("%d ",arr.A[i]);
} 

struct ARRAY *UNION(struct ARRAY *arr1,struct ARRAY *arr2){
    struct ARRAY *arr3=(struct ARRAY *)malloc(sizeof(struct ARRAY));
    int i,j,k;
    i=k=j=0;
    while(i<arr1->length && j<arr2->length)
 {
 if(arr1->A[i]<arr2->A[j])
 arr3->A[k++]=arr1->A[i++];
 else if(arr2->A[j]<arr1->A[i])
 arr3->A[k++]=arr2->A[j++];
 else
 {
 arr3->A[k++]=arr1->A[i++];
 j++;
 }
 }
 for(;i<arr1->length;i++)
 arr3->A[k++]=arr1->A[i];
 for(;j<arr2->length;j++)
 arr3->A[k++]=arr2->A[j];
 
 arr3->length=k;
 arr3->size=10;
    return arr3;


}

struct ARRAY *intersection(struct ARRAY *arr1,struct ARRAY *arr2){
    struct ARRAY *arr4=(struct ARRAY *)malloc(sizeof(struct ARRAY));
    int i,j,k;
    i=k=j=0;
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j])
 i++;
 else if(arr2->A[j]<arr1->A[i])
 j++;
 else if(arr1->A[i]==arr2->A[j])
 {
 arr4->A[k++]=arr1->A[i++];
 j++;
 }
    }
    arr4->length=k;
    arr4->size=10;
    return arr4;
    }

int main(){

    struct ARRAY arr1={{2,5,6,7},4,10};
    struct ARRAY arr2={{5,6,11,12},4,10};
    struct ARRAY *arr3;
    struct ARRAY *arr4;
    arr3=UNION(&arr1,&arr2);
    display(*arr3);
    arr4=intersection(&arr1,&arr2);
    display(*arr4);





}

