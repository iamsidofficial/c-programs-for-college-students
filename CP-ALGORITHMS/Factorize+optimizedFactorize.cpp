#include <bits/stdc++.h>
using namespace std;


void factorize(int n){
	for(int i=2;i<=n;i++){
		int ct=0;
		if(n%i==0){
			while(n%i==0){
				ct++;
				n=n/i;
			}
		}
		cout<<i<<"^"<<ct<<" ";
	}
}

void optimizedFactorize(int n){
	int ct=0;
	for(int i=2;i*i<=n;i++){
		
		if(n%i==0){
			while(n%i==0){
				ct++;
				n=n/i;
			}
		}
		cout<<i<<"^"<<ct<<" ";
	}
	//out of loop
	cout<<n<<"^"<<1<<endl;


}
int main(){
   int n;
   cin>>n;
   optimizedFactorize(n);





return 0;    
}