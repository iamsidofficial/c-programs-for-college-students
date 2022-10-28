#include <bits/stdc++.h>
using namespace std;

int main(){
   int arr[8]={1,2,1,2,3,5,3,9};
   int n=sizeof(arr)/sizeof(arr[0]);
   //XOR
   int cxor=0;
   for(int i=0;i<n;i++){
   	cxor=cxor^arr[i];
   }
// Pos
   int pos=0;
   while((cxor&1)==0){
   	pos++;
   	cxor>>1;
   }

// Filter out the numbers from the array which have set bit at 'pos'
   int setA=0;
   int setB=0;
   int mask=1<<pos;

   for(int i=0;i<n;i++){
   	if((arr[i]&mask)>0){
   		setA=setA^arr[i];
   	}
   	else{
   		setB=setB^arr[i];
   	}
   }

   cout<<setA<<endl;
   cout<<setB<<endl;
   




return 0;    
}