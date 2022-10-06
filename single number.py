from collections import Counter
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        n=Counter(nums)
        print(n)
        for k,v in n.items():
            if v==1:
                return k
        return-1
        
