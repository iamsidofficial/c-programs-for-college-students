#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
 
#define N 1000000007
int main(){
 
    ll x,y;
    cin>>x>>y;
    ll t;
    cin>>t;
    ll a[6];
    a[0]=(x-y);
    a[1]=x;
    a[2]=y;
    a[3]=(y-x);
    a[4]=-x;
    a[5]=-y;
 
    ll k=a[t%6];
 
    ll h=(k%N+N)%N;
    cout<<h<<endl;
 
 
 
 
return 0;    
}