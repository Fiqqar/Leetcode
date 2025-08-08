class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        d = {}
        p = 0
        for i in nums:
            if i in d:
                d[i] += 1
            else:
                d[i] = 1
        for num in d:
            val = d[num]
            for i in range(val):
                p += i
        return p
        