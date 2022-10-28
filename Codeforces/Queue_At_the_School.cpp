#include <bits/stdc++.h>
using namespace std;
 
int main(){
   
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int hhh=223;
    int ct=0;
    for(int j=0;j<k;j++){
       for(int i=0;i<n-1;i++){
        if(s[i]=='B' && s[i+1]=='G'){
            s[i]='G';
            s[i+1]='B';
            i++;
        }
        
 
 
    }
    }
    
    cout<<s<<endl;
   
 
 
 
 
return 0;    
}