// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<4) return ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> temp(4);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int left=j+1;
                int right=n-1;
                long long int req=(long long )target-nums[i]-nums[j];
                while(left<right){
                     if(req>nums[left]+nums[right]) left++;
                     else if(req<nums[left]+nums[right]) right--;
                     else{
                        temp[0]=nums[i];
                        temp[1]=nums[j];
                        temp[2]=nums[left];
                        temp[3]=nums[right];
                        ans.push_back(temp);
                        while(left<right && temp[2]==nums[left]) left++;
                        while(left<right && temp[3]==nums[right]) right--;
                     }
                }
             while(j+1<n && nums[j+1]==nums[j]) j++;
            }
             while(i+1<n && nums[i+1]==nums[i]) i++;
        }
        return ans;
    }
};