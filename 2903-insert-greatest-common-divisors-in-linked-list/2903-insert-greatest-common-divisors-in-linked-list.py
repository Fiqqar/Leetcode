# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr = head;

        while curr and curr.next:
            great = gcd(curr.val, curr.next.val)

            nn = ListNode(great)

            nn.next = curr.next
            curr.next = nn

            curr = nn.next
        return head

        
        