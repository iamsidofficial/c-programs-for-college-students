#include <stdio.h>

#define N 100

int max(int arr[N]){
	int max = 0;
	for(int i=0;i<N;i++){
		if(arr[i]> max){
			max = arr[i];		}
	}
	printf("%d",max);
}

int main(){
	int arr[N]= {214,2134,3456,54};
        max(arr);
}

