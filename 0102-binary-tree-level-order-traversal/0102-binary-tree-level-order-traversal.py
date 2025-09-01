# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        if not root:
            return res
        arr = deque()
        arr.append(root)
        while len(arr) != 0:
            ans = []
            length = len(arr)
            for i in range(length):
                ele = arr.popleft()
                ans.append(ele.val)
                if ele.left:
                    arr.append(ele.left)
                if ele.right:
                    arr.append(ele.right)
            res.append(ans)
        return res