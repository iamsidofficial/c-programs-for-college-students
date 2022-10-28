#include <bits/stdc++.h>
using namespace std;
int isodd(int x){
	if(x&1){
		return 1;
	}
	else{
		return 0;
	}
}

int getithbit(int x,int i){
	/* 
    000000101
  & 000000100
    000000100 > 0 =>set bit
    000000100 ==0 =>unset bit
	*/
	int mask=(1<<i);
	if((x&mask)==0){
		return 0;
	}
	else{
		return 1;
	}
}

//to set pass by reference 
int setithbit(int &x,int i){
	/* 0000101
	  |0000010
     =>0000111
	*/
	int mask=1<<i;
	x=x|mask;
	return x;
}

int clearbit(int &x,int i){
	/*
    00000101
  & 11111011
  & 00000001
    00000001
	*/
	int mask=~(1<<i);
	x=(x&mask)&x;
    return x;
}
int updateithbit(int &x,int i,int v){
	/* 
	    *
    0010101
    0010001=>clear the ith bit first
  ||0000100=>if want to set this bit
  ||0000000=>if unset the bit

	*/
	clearbit(x,i);
	int mask=v<<i;
	x=x|mask;
	return x;
}

int clearlastibits(int &x,int i){
	/*    
	      *****
	  00001101001
   &11111100000=>~0 or -1
   000001100000
	*/
	int mask=(~0)<<i;
	x=x&mask;
	return x;
}

int clearrangebits(int &x,int i,int j){
	/* 
	   ****
  000110111
           j
  mask=>111000000
       |000000011(2^i-1)
        111000011
  no. & mask=>000000011      
	*/
	int a=(~0)<<j+1;
	int b=(1<<i)-1;
	int mask=a|b;
	x=x&mask;
	return x;
}

int countsetbits(int n){
  int ct=0;
	while(n>0){
		
		ct+=(n&1);
		n=n>>1;
	}
	return ct;
}

int convertTobinary(int n){
	int ans=0;
	int p=1;
	while(n>0){
		ans+=(n&1)*p;
		n=n>>1;
		p=p*10;
	}
	return ans;
}
int main(){
	
	cout<<log2(6);
	
	
   




return 0;    
}