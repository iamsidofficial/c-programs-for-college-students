class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n=len(nums)
        for i in range(n):
            if nums[i]<=0:
                nums[i]=n+1
        
        for i in range(n):
            index=abs(nums[i])
            if index>n:
                continue
            elif nums[index-1]<0:
                continue
            else:
                nums[index-1]*=-1
        
        for i in range(n):
            if nums[i]>0:
                return i+1
        return n+1
