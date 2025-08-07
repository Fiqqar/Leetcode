class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        lent = len(nums)
        res = [0] * (2 * lent)
        for i in range(lent):
            res[i] = nums[i]
            res[i+lent] = nums[i]
        return res
        