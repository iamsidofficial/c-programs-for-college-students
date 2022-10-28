  #include <bits/stdc++.h>
  using namespace std;
  
  const int N=1e5+10;
vector<int>g[N];
int depth[N];
int parent[N];
void dfs(int vertex,int par=-1){
	/*
    Taking action on child before entering the child node
	*/
	parent[vertex]=par;
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

	vector<int> path(int v){
		vector<int>ans;
	    while(v!=-1){
	    	ans.push_back(v);
	    	v=parent[v];

	    }
	    reverse(ans.begin(),ans.end());
	    return ans;
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
   dfs(1);
   int a,b;
   cin>>a>>b;
   vector<int>a1=path(a);
   vector<int>a2=path(b);
   int min_len=min(a1.size(),a2.size());
   int lca=-1;
   for(int i=0;i<min_len;i++){
   	if(a1[i]==a2[i]){
   		lca=a1[i];
   	}
   	else{
   		break;
   	}
   }
   cout<<lca<<endl;


  return 0;    
  }