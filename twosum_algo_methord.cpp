/*# Approach
problem practice link    https://leetcode.com/problems/two-sum
problem statement:
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
ex;-
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

*/


//# Code

#include<vector>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {//step1 firstdefine function
        vector<int> ans;//step3 defining ans
        using namespace std;
        for(int i=0;i<(int)nums.size();i++){
            for(int j=(i+1); j< nums.size();j++){
                if (nums[i]+nums[j]==target)
                {   ans.push_back(i);
                    ans.push_back(j);return ans;//step4  this is the actual answer
                }
            }
        } 
        vector<int> ansd;
        return ansd;//step2 then do the return type properly
    }
};
