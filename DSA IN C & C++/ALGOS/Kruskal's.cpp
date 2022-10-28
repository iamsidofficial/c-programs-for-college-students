#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N];
int size[N];

void make(int i){
	parent[i]=i;
	size[i]=1;
}

int find(int u){
    if(u==parent[u]){
    	return u;
    }
    else{
    	return parent[u]=find(parent[u]);
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
	int minimum_cost=0;
	int n,m;
	cin>>n>>m;
	vector<pair<int,pair<int,int>>> edges;
	while(m--){
		int u,v,wt;
		cin>>u>>v>>wt;
		edges.push_back({wt,{u,v}});
	}

	for(int i=1;i<=n;i++){
		make(i);
	}

	sort(edges.begin(),edges.end());
	for(auto &edge:edges){
		int u,v,wt;
		u=edge.second.first;
		v=edge.second.second;
		wt=edge.first;
		if(find(u)==find(v)){
			continue;
		}
		Union(u,v);
		minimum_cost+=wt;
		cout<<u<<" "<<v<<" "<<wt<<endl;

	}
	cout<<minimum_cost<<endl;
   




return 0;    
}