# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        nums=[]
        cur=head
        temp=ListNode(0)
        a=temp
        while cur!=None:
            nums.append(cur.val)
            cur=cur.next
        print(nums)
        if k>len(nums) and len(nums)!=0:
            k=k%len(nums)
        nums[:]=nums[-k:]+nums[:-k]
        print(nums)
        for i in nums:
            x=ListNode(i)
            a.next=x
            a=a.next
        return temp.next
            
        
