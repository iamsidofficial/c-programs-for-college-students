#include <bits/stdc++.h>
using namespace std;

int main(){
   int n;
   cin>>n;

   vector<int> primes={2,3,5,7,11,13,17,23,29};//10 prime numbers
   int m=primes.size();
   int ans=0;
   for(int i=1;i<(1<<m);i++){
   	int lcm=1;
   	for(int j=0;j<m;j++){
   		if((i>>j)&1){
   			//cout<<primes[j]<<" ";
   			lcm*=primes[j];
   		}
   	}
   	if(__builtin_popcount(i)%2==0){
   		ans-=(n/lcm);
   	}
   	else{
   		ans+=(n/lcm);
   	}
   }

   cout<<ans<<endl;




return 0;    
}