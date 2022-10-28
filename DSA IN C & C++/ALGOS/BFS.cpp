#include <bits/stdc++.h>
using namespace std;

int visited[7]={0};
int A[7][7]={   {0,0,0,0,0,0,0},
	            {1,0,1,0,0,0,0},
	            {1,1,0,1,1,0,0},
	            {1,0,1,0,1,0,0},
	            {0,0,1,1,0,1,1},
	            {0,0,0,0,1,0,0},
	            {0,0,0,0,1,0,0}
	        };

queue<int>Q;
void BFS(int i){
	cout<<i<<" ";
	visited[i]=1;
    Q.push(i);
	while(Q.size()>0){

	bb
		int u=Q.front();
		Q.pop();
		for(int v=1;v<=7;v++){
			if(visited[v]==0 && A[u][v]==1){
				cout<<v<<" ";
				visited[v]=1;
				Q.push(v);

			}
		}
	}
}
int main(){
  BFS(2);



return 0;    
}