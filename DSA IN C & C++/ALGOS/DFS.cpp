#include <bits/stdc++.h>
using namespace std;
int visited[7]={0};
int A[7][7]={{0,0,0,0,0,0,0},
                {1,0,1,0,0,0,0},
                {1,1,0,1,1,0,0},
                {1,0,1,0,1,0,0},
                {0,0,1,1,0,1,1},
                {0,0,0,0,1,0,0},
                {0,0,0,0,1,0,0}};

void DFS(int u){
	
	cout<<u<<" ";
	visited[u]=1;
	
	for(int v=1;v<=7;v++){
		if(A[u][v]!=0 && visited[v]==0){
			DFS(v);		}
	}

}                
int main(){

	DFS(1);
   




return 0;    
}