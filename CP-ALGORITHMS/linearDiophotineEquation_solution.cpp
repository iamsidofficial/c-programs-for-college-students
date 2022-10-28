#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}

vector<int> extendedGCD(int a,int b){
	if(b==0) return {1,0};

	vector<int>result=extendedGCD(b,a%b);
	int x=result[1];
	int y=result[0]-(a/b)*result[1];
	return {x,y};
}

int main(){

	int a,b,c;
	cin>>a>>b>>c;
	int g=gcd(a,b);
	int k=c/g;
	if(c%g!=0) cout<<"No solution"<<endl;

	else{

		vector<int>result=extendedGCD(a,b);

		int x=result[0]*k;
		int y=result[1]*k;
		cout<<x<<" "<<y;

	}
	
   




return 0;    
}