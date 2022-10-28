#include<stdio.h>

void swap(int *x,int *y){
	int temp=*y;
	*y=*x;
	*x=temp;
}


void selectionSort(int A[],int n){

	for(int i=0;i<n-1;i++){
		int k=i;
		for(int j=i;j<n;j++){
			if(A[k]>A[j]){ //if find smaller no the k=j
				k=j;
			}
		}
		swap(&A[i],&A[k]);
	}
}

int main(){

	int n;
	scanf("%d",&n);
	int A[n];
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}


    selectionSort(A,n);

    for(int i=0;i<n;i++){
		printf("%d ",A[i]);
	}




    
	return 0;
}