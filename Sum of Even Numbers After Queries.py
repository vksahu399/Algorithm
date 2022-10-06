class Solution:
    def sumEvenAfterQueries(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        s=0
        for i in nums:
            if i%2==0:
                s+=i
        print(s)
        l=[]
        for i in queries:
            if nums[i[1]]%2==0:
                s-=nums[i[1]]
            nums[i[1]]+=i[0]
            if nums[i[1]]%2==0:
                s+=nums[i[1]]
            l.append(s)
        return l
                    
        
            
