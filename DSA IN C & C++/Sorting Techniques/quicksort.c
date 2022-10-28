#include<stdio.h>
#include<limits.h>
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int A[],int low,int high){
	int i=low;
	int j=high;
	int pivot=A[low];
	do{
		do{i++;}while(A[i]<=pivot);
		do{j--;}while(A[j]>pivot);
		if(i<j){
			swap(&A[i],&A[j]);
		}
		
	}while(i<j);
  swap(&A[low],&A[j]);
  return j;
}

void QuickSort(int A[],int low,int high){
	int j;
	if(low<high){
		j=partition(A,low,high);
		QuickSort(A,low,j);
		QuickSort(A,j+1,high);
	}
}

int main(){
    int n;
	scanf("%d",&n);
	int A[n+1];
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	A[n]=INT_MAX;


    QuickSort(A,0,n);

    for(int i=0;i<n;i++){
		printf("%d ",A[i]);
	}


	return 0;
}