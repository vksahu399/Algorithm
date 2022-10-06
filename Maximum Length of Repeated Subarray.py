class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        n=len(nums1)
        m=len(nums2)
        len_=0
        dp=[[0]*(n+1)for i in range(m+1)]
        for i in range(1,m+1):
            for j in range(1,n+1):
                if nums1[j-1]==nums2[i-1]:
                    dp[i][j]=dp[i-1][j-1]+1
                len_=max(len_,dp[i][j])
        return len_
