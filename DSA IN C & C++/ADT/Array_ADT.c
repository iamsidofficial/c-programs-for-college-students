#include <stdio.h>
#include<stdlib.h>

struct ARRAY{
    int *A;
    int length;
    int size;
};

void display(struct ARRAY arr){
    printf("\nElements are:\n");
    for(int i=0;i<arr.length;i++){
        printf("%d ",arr.A[i]);
    }
}

int main(){
   struct ARRAY arr;
   printf("Enter size of array:");
   scanf("%d",&arr.size);
   arr.A=(int*)malloc(sizeof(int)*arr.size);
   int n;
   printf("\nEnter no of elements:");
   scanf("%d",&n);
   printf("\nEnter all the elements:");
   for(int i=0;i<n;i++){
       scanf("%d",&arr.A[i]);

   }
   arr.length=n;
   display(arr);





    return 0;
}