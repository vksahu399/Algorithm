# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        l=[]
        cur=head
        while(cur!=None):
            l.append(cur.val)
            cur=cur.next
        if l==l[::-1]:
            return True
        else:
            return False
        
            
            
        
