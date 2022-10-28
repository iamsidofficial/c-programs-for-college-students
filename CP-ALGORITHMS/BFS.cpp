#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>g[N];
int visited[N];
int level[N];

void bfs(int source){
	queue<int>q;
	q.push(source);
	visited[source]=1;

	while(!q.empty()){

		int current_v=q.front();
		cout<<current_v<<" ";
		q.pop();
		for(int child:g[current_v]){
			if(visited[child]) continue;
			q.push(child);
			visited[child]=1;
			level[child]=level[current_v]+1;

		}
		
		
    
	}

cout<<endl;
	
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
   bfs(1);
   for(int i=1;i<=n;i++){
   	cout<<i<<":"<<level[i]<<endl;
   }







return 0;    
}