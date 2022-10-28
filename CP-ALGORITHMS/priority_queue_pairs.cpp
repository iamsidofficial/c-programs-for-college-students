#include<bits/stdc++.h>
using namespace std;
int mod(int x,int y){
    if(x-y<0){
        return y-x;
    }
    return x-y;
}
vector<int> findClosestElements(vector<int> arr, int k, int x) {
    vector<int>ans;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>q;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        
        q.push({mod(arr[i],x),arr[i]});
    }
    while(k--)
    {
        ans.push_back(q.top().second);
        q.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
        
}

print(vector<int>v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int>arr={1,2,3,4,5};
    print(findClosestElements(arr,4,3));
    return 0;   
}