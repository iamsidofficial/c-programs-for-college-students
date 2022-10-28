#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long double r,x,y,a,b;
    cin>>r>>x>>y>>a>>b;
    long double d1=(x-a)*(x-a);
    long double d2=(y-b)*(y-b);
 
    long double d=(sqrt(d1+d2));
    cout<<ceil(d/(2*r))<<endl;
 
   
 
 
 
 
return 0;    
}