# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur=head
        prev=None
        while cur!= None and cur.next!=None:
            if cur.val==cur.next.val:
                while cur.next != None and cur.val==cur.next.val:
                    cur=cur.next
                if prev is None:
                    head=cur.next
                else:
                    prev.next=cur.next
                cur=cur.next
            else:
                if prev is None:
                    prev=cur
                else:
                    prev=prev.next
                cur=cur.next
                
        return head
        
