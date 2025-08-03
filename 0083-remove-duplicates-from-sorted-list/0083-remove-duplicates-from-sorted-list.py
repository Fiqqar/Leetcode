# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        list = head
        while (list and list.next):
            if(list.next.val == list.val):
                list.next = list.next.next
                continue
            list = list.next
        return head

        