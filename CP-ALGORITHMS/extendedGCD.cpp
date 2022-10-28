#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	if(b==0){
		return a;
	}

	return gcd(b,a%b);
}

//To solve ax+by=gcd(a,b)
vector<int> extendedGCD(int a,int b){
	if(b==0){
		return {1,0};
	}
	vector<int> result=extendedGCD(b,a%b);
    
	//After recursions
	int smallX=result[0];
	int smallY=result[1];

	int x=smallY;
	int y=smallX-(a/b)*smallY;
	return {x,y};
}

int main(){
	int a,b;
	cin>>a>>b;
	
	vector<int>v=extendedGCD(a,b);

	cout<<v[0]<<" and "<<v[1]<<endl;
   




return 0;    
}