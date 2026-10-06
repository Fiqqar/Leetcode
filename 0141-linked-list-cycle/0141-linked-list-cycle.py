# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        fastptr = head
        slowptr = head
        while fastptr is not None and fastptr.next is not None:
            slowptr = slowptr.next
            fastptr = fastptr.next.next
            if slowptr == fastptr:
                return 1
        return 0
        