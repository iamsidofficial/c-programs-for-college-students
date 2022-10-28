#include <bits/stdc++.h>
using namespace std;
 
int bitdiff(int x,int y,int n){
    int ct=0;
    int i=0;
    while(i<=n){
        int a=x&1;
        int b=y&1;
        if(a!=b) ct++;
        x=x>>1;
        y=y>>1;
        i++;
    }
    return ct;
}
int main(){
    int ct=0;
    int n,m,k;
    cin>>n>>m>>k;
    int a[m+1];
    for(int i=0;i<m+1;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        if(bitdiff(a[i],a[m],n)<=k) ct++;
    }
    cout<<ct<<endl;
   
 
 
 
 
return 0;    
}