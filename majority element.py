class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n=len(nums)
        p=nums[0]
        m=[]
        m.append(1)
        for i in range(1,len(nums)):
            if nums[i]==p:
                m.append(m[i-1]+1)
            elif m[i-1]==0:
                p=nums[i]
                m.append(m[i-1]+1)
            else:
                m.append(m[i-1]-1)
        f=nums.count(p)
        if f>n//2:
            return p
        else:
            return -1
            
            
