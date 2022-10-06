class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n=sorted(nums)
        mi=1
        for i in n:
            if i==mi:
                mi+=1
            if i>mi:
                return mi
        return mi
            
            
            
        
