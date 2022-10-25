// Q. remove all duplicates of length k from the string 

#include<std/bitsc++.h>
using namespace std;

int main()
{

      string s, int k;
      cout<<"Enter the string and the value of k"
      cin>>s>>k;
        
        vector<pair<char,int>>v;
        
        for(char c:s)
        {
            if(v.empty() || v.back().first !=c)
            {
                v.push_back(make_pair(c,1));
                
            }
            else
            {
                v.back().second++;
                if(v.back().second == k)
                    v.pop_back();
            }
        }
        
        string result = "";
        for(auto res: v)
        {
            result.append(res.second,res.first);
        }
        
        cout<<result;
 }
