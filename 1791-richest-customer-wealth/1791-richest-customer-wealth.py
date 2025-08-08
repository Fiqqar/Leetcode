class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        maxv = 0
        for i in accounts:
            wealth = sum(i)
            maxv = max(maxv, wealth)
        return maxv
        