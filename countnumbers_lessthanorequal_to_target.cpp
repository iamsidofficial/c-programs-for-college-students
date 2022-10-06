#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
cpp program to find the count of numbers in an array of numbers less than or equal to a given target (implemented using binary search algorithm)
Author: Chandana
*/
int main(){
    int n,k,x;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>x;
        v[i]=x;
    }
    cout<<"Enter your target"<<endl;
    cin>>k;
    sort(v.begin(),v.end());
    int l=0,h=n-1,ans=-1,mid;
    while(l<=h){
        mid=h-(h-l)/2;
        if(k>=v[mid]){
            l=mid+1;
            ans=mid;
        }
        else{
            h=mid-1;
        }
    }
    cout<<"Number of numbers less than or equal to your target "<<k<<" is: "<<ans+1<<endl;
    return 0;
}
