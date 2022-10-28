#include <bits/stdc++.h>
using namespace std;
#define N 1000000

vector<int> v(N,1);
vector<int> p(N,0);

void primeSieve(vector <int> &v,vector <int> &p){
	v[0]=v[1]=0;
	for(long long i=2;i<N;i++){
		
     if(v[i]==1){
     	for(long long j=i*i;j<=N;j++){
			v[j]=0;
			p[j]=i;
		}
     }
		
	}
}


void factors(int n){
	int x=v[n];
	int t=n;
	while(n!=1){
		cout<<v[n]<<" "<<n/v[n];
		n=n/v[n];


	}
}
int main(){
	 for(int i=0;i<N;i++){
	    v[i]=i;
     }
	 primeSieve(v,p);
	 cout<<p[2]<<" "<<p[16];
   







return 0;    
}