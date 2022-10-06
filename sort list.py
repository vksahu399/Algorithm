# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur=head
        temp=ListNode()
        x=temp
        l=[]
        while cur is not None:
            l.append(cur.val)
            cur=cur.next
        l=sorted(l)
        for i in l:
            s=ListNode(i)
            x.next=s
            x=x.next
        return temp.next
            
            
            
            
            
            
        
