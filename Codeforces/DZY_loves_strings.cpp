#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    int a[26];
    for(int i=1;i<=26;i++){
        cin>>a[i-1];
    }
    //cout<<a[1];
  
    int sum=0;
    for(int i=1;i<=s.size();i++){
        int x=s[i-1]-96-1;
       sum+=i*a[x];
    }
      sort(a,a+26);
    for(int i=s.size()+1;i<=s.size()+n;i++){
        sum+=i*a[25];
            }
 
  cout<<sum<<endl;         
   
 
 
 
 
return 0;    
}