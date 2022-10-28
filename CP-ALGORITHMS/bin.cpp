#include <bits/stdc++.h>
using namespace std;

int main(){
   int t;
   cin>>t;
   while(t--){
    int n;
    cin>>n;
    map<int,int>m;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        m[x]++;
    }
    vector<pair<int,int>>v;
    int i=0;
    for(auto it:m){
        v[i].first=it.first;
        v[i].second=it.second;
        i++;

    }

   }




return 0;    
}   