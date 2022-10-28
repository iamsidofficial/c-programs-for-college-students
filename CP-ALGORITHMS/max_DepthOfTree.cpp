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
	
	for(int child:g[vertex]){
		
		if(child==par) continue;
		
		depth[child]=depth[vertex]+1;
		
		dfs(child,vertex);
		
		/*
		Take action on child after exiting the child node
		*/
		

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
   int max_depth=-1;
   int max_depthNode;
   for(int i=1;i<=n;i++){
   	if(max_depth<depth[i]){
   		max_depth=depth[i];
   		max_depthNode=i;
   	}
   	depth[i]=0;
   }
   dfs(max_depthNode,0);
   max_depth=-1;
   for(int i=1;i<=n;i++){
   		if(max_depth<depth[i]){
   		max_depth=depth[i];
   		max_depthNode=i;
   	}
   }
   cout<<max_depth<<endl;




return 0;    
}