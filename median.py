class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n=sorted(nums1+nums2)
        print(n)
        if len(n)%2!=0:
            i=len(n)//2
            return n[i]
        else:
            i=len(n)//2
            return (n[i]+n[i-1])/2
        
