#include <bits/stdc++.h>
using namespace std;
int minS(long long int a,long long int b){
    if(a>b) return b;
    else return a;
}
int main(){
   long long int n,m;
   cin>>n>>m;
  
   
   long long int d=n-(m-1)-1;
 
   long long int max=d*(d+1)/2;
   
long long int a=n/m;
long long int b=n%m;
 
long long int min=(a*(a+1)/2)*(n%m)+ ((a-1)*a/2)*(m-b);
 
cout<<min<<" "<<max<<endl;
   
 
 
 
   
 
 
 
return 0;    
}