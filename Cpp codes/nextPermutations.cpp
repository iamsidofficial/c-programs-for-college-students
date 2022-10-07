// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void swap(int i,int j,vector<int>& nums){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    void reverse(int i,int j,vector<int>& nums){
        while(i<j){
            swap(i,j,nums);
            i++;j--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int index1=-1,index2;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]>nums[i]){
                index1=i;
                break;
            }
        }
        if(index1==-1){
            reverse(0,n-1,nums);
            return;
        }
        for(int i=n-1;i>index1;i--){
            if(nums[index1]<nums[i]){
                index2=i;
                break;
            }
        }
        swap(index1,index2,nums);
        reverse(index1+1,n-1,nums);
    }
};