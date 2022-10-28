#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int>g[N];
int sum[N];
int depth[N],height[N];
int even_count[N];
void dfs(int vertex,int par){
	/*
    Taking action on child before entering the child node
	*/
	if(vertex%2==0) even_count[vertex]++;
	sum[vertex]+=vertex;
	//cout<<sum[vertex]<<endl;
	for(int child:g[vertex]){
		
		if(child==par) continue;
		
		
		dfs(child,vertex);
		
		sum[vertex]+=sum[child];
		/*
		Take action on child after exiting the child node
		*/
		even_count[vertex]+=even_count[child];

	}
	/*
	Taking sction on vertex before exiting the vertex node
	*/
	
	}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		cout<<i<<"="<<sum[i]<<" "<<"ec="<<even_count[i];
		cout<<endl;
	}
	




return 0;    
}