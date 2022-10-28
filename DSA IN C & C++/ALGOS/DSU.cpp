#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int parent [N];
int size[N];

void make(int n){
	parent[n]=1;
    size[n]=1;
}

int find(int v){
	if(parent[v]==v){
		return v;
	}
	else{
		return parent[v]=find(parent[v]);//path compression
	}
}

void Union(int a,int b){
	a=find(a);
	b=find(b);
	if(a!=b){
		if(size[a]<size[b]){
			swap(a,b);
		}
		parent[b]=a;
		size[a]+=size[b];
	}
}
int main(){

	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		make(x);
	}
    
	while(k--){
		int u,v;
		cin>>u>>v;
		Union(u,v);
	}


return 0;    
}