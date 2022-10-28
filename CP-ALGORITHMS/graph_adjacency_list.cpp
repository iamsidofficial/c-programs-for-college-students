#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int> g[N];
bool vis[N];

void dfs(int vertex){
    cout<<vertex<<endl;
    vis[vertex]=true;
	for(int child:g[vertex]){
        
		if(vis[child]) continue;

		dfs(child);
	}


}

int main(){
	int n,m;
	cin>>n>>m;
	//vertices=n edges=m
	for(int i=0;i<m;i++){
	   int a,b;
	   cin>>a>>b;
	   g[a].push_back(b);
	   g[b].push_back(a);

	}

	dfs(1);

   




return 0;    
}