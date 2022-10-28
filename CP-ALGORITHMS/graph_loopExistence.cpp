#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>g[N];
int visited[N]={0};
vector<vector<int>>cc;
vector<int>current_cc;
int dfs(int vertex,int par){
	current_cc.push_back(vertex);
	//cout<<vertex<<endl;
	visited[vertex]=1;
	int isLoop=0;
	for(int child:g[vertex]){
		if(visited[child]==1 && child==vertex) continue;
		if(visited[child]){
			return 1;
		}
		isLoop |=dfs(child,vertex);
	}
	return isLoop;
}
int main(){
   int m,n;
   cin>>m>>n;
   for(int i=0;i<n;i++){
   	int a,b;
   	cin>>a>>b;
   	g[a].push_back(b);
   	g[b].push_back(a);
   }
   
   for(int i=1;i<=m;i++){
   	if(visited[i]) continue;
   	int a=0;
   	a=dfs(i,0);
   	if(a==1) {
   		cout<<"YES"<<endl;
   		break;
   	}
   }



return 0;    
}