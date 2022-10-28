#include <bits/stdc++.h>
using namespace std;

void overlaynumber(string s,int number){
    int j=0;
	while(number>0){
		if(number&1){
			cout<<s[j];
		}
		j++;
		number=number>>1;
	}
}
void subset(string s){
	int n=s.size();
	for(int i=0;i<(1<<n);i++){
		overlaynumber(s,i);
		cout<<" ";
	}
}
int main(){
	string s="aab";
	subset(s);
	
   




return 0;    
}