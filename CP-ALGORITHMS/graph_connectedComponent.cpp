#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>g[N];
int visited[N]={0};
vector<vector<int>>cc;
vector<int>current_cc;
void dfs(int vertex){
	current_cc.push_back(vertex);
	//cout<<vertex<<endl;
	visited[vertex]=1;
	for(int child:g[vertex]){
		if(visited[child]) continue;
		dfs(child);
	}
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
   int ct=0;
   for(int i=1;i<=m;i++){
   	if(visited[i]) continue;
   	current_cc.clear();
   	dfs(i);
   	cc.push_back(current_cc);
   	ct++;
   }
   for(auto c1:cc){
   	for(auto c2:c1){
   		cout<<c2<<" ";
   	}
   	cout<<endl;
   }



return 0;    
}