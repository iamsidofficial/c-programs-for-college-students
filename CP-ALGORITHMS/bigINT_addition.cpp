#include <bits/stdc++.h>
using namespace std;


int charToint(char s){
	return s-'0';
}

char digitTochar(int n){
	return '0'+n;
}
string addNumbers(string n1,string n2){
	//Make sure that second number is larger
	if(n1.length()>n2.length()){
		swap(n1,n2);
	}
	//result array
	string result="";
    
    //reverse the numbers
	reverse(n1.begin(),n2.end());
	reverse(n2.begin(),n2.end());\

	int carry=0;

	//Add digits upto n1.length()
	for(int i=0;i<n1.length();i++){
		int d1=charToint(n1[i]);
		int d2=charToint(n2[i]);
		int sum=d1+d2+carry;
		int output_digit=sum%10;
		carry=sum/10;
		result.push_back(digitTochar(output_digit));
	}
   //Add remaining digits of n2 with remaining carry
	for(int i=n1.length();i<n2.length();i++){
		int d2=charToint(n2[i]);
		int sum=d2+carry;
		int output_digit=sum%10;
		carry=sum/10;
		result.push_back(digitTochar(output_digit));

	}

	if (carry==1){
		result.push_back('1');
	}
	
	reverse(result.begin(),result.end());
	return result;

}
int main(){
   //store numbers in two strings
	string s1,s2;
	cin>>s1>>s2;

	string result=addNumbers(s1,s2);
    cout<<result<<endl;

return 0;    
}