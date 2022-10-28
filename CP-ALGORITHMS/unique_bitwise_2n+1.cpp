#include <bits/stdc++.h>
using namespace std;

int main(){
   int arr[7]={1,2,1,9,2,5,5};
   int n=sizeof(arr)/sizeof(arr[0]);
   int cxor=arr[0];
   for(int i=1;i<n;i++){
   	cxor=cxor^arr[i];
   }
   cout<<cxor;




return 0;    
}