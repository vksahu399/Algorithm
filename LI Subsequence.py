class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        sub=[]
        sub.append(nums[0])
        def bs(sub,n):
            l=0
            h=len(sub)-1
            while(l<h):
                mid=(l+h)//2
                if sub[mid]==n:
                    return mid
                if sub[mid]<n:
                    l=mid+1
                else:
                    h=mid
            return l
        for i in range(len(nums)):
            if nums[i]>sub[-1]:
                sub.append(nums[i])
            else:
                j=bs(sub,nums[i])
                sub[j]=nums[i]
        return len(sub)
                
