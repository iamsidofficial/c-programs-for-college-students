#include <bits/stdc++.h>
using namespace std;

void Insert(int A[],int n){
	int temp=A[n];
	int i=n;
	while(i>1&&temp>A[i/2]){
		A[i]=A[i/2];
		i=i/2;
	}
	A[i]=temp;
}

void Create(int A[],int n){
	for(int i=2;i<n;i++){
		Insert(A,i);
	}

}

int main(){
	int A[9]={0,5,6,12,10,30,15,35,40};
	Create(A,9);
	for(int i=1;i<9;i++){
		cout<<A[i]<<" ";
	}

   




return 0;    
}