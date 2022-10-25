// Online C++ compiler to run C++ program online
    #include<bits/stdc++.h>
    using namespace std;
    
    int main(){
        
    string s;
    cin>>s;
    
    
    unordered_map<char,int> mpp;
    int i=0;
    int j=0;
    int mx = INT_MIN;
        if(s.length() == 0){
            return 0;
        }
    while(j<s.length()){
        mpp[s[j]]++;
        if(mpp.size() == j-i+1){
            mx = max(mx, j-i+1);
            j++;
        }
        else if(mpp.size() < j-i+1){ 
            while(mpp.size() < j-i+1){
                mpp[s[i]]--;
                if(mpp[s[i]] == 0){
                   mpp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
   cout<< mx;
    }
