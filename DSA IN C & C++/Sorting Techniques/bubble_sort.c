#include <stdio.h>

void swap(int *x,int *y){
	int temp=*y;
	*y=*x;
	*x=temp;
}

void bubblesort(int A[],int n){

	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(A[j]>A[j+1]){
				swap(&A[j],&A[j+1]);
			}

		}
	}

}

int main(){
	int n;
	scanf("%d",&n);
	int A[n];
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}


    bubblesort(A,n);
      for(int i=0;i<n;i++){
		printf("%d ",A[i]);
	}
	return 0;
}