#include <bits/stdc++.h>
using namespace std;

void updateArr(vector<int> &v,int x){
	for(int i=0;i<32;i++){
		int ithbit=x&(1<<i);
		if(ithbit){
			v[i]++;
		}
	}
}

 int numfrombit(vector<int>sumArr){
	int v=0;
	int p=1;
	for(int i=0;i<32;i++){
         v+=sumArr[i]*(1<<i);
         
	}
	return v;
}
int  uniqueno3(vector<int>arr){
	vector<int> sumArr(32,0);

	for(int i=0;i<arr.size();i++){
		updateArr(sumArr,arr[i]);
	}

	for(int i=0;i<32;i++){
		sumArr[i]=sumArr[i]%3;
	}
	return numfrombit(sumArr);
}

print(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
	vector<int>v={1,1,1,2,2,2,3,3,3,9};
	cout<<uniqueno3(v);
	


   




return 0;    
}