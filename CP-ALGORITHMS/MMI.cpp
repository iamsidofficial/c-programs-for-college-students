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

int MMI(int a,int m){
	if(gcd(a,m)!=1){
		return -1;
	}
	
    vector<int>ans=extendedGCD(a,m);
    return (ans[0]%m+m)%m;//to make result positive
}
int main(){
	int a,m;
	cin>>a>>m;
	cout<<MMI(a,m);

   




return 0;    
}