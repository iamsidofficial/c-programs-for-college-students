#include <bits/stdc++.h>
using namespace std;
 
int main(){
   
    long long int n,k;
    cin>>n>>k;
    long long int a[k];
    long long int c[k];
    for(long long int i=0;i<k;i++){
        cin>>a[i];
    }
    long long int sum=0;
    for(long long int i=0;i<k-1;i++){
        long long int d=a[i+1]-a[i];
        if(d<0) sum+=n-a[i]+a[i+1];
 
        else sum+=d;
    }
    for(long long int i=0;i<k-1;i++){
        c[i]=a[i+1]-a[i];
    }
    sum+=a[0]-1;
  
    cout<<sum<<endl;
    cout<<endl;
 
 
 
 
 
 
return 0;    
}