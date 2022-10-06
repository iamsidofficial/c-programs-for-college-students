#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
cpp program to find the count of each key(string) in a given register using hashmap
Note that this program is case-sensitive
Author: Chandana
*/
int main(){
    int n;
    string x;
    unordered_map<string,int> um;
    cout<<"Enter the size of the register"<<endl;
    cin>>n;
    vector<string> v(n);
    cout<<"Enter the name of each entity"<<endl;
    for(int i=0;i<n;i++){
        cin>>x;
        v[i]=x;
        um[x]++;
    }
    for(auto x:um){
        cout<<"Number of entities named as "<<x.first<<" = "<<x.second<<endl;
    }
    return 0;
}
