class Solution:
    def theMaximumAchievableX(self, num: int, t: int) -> int:
        n = num
        for i in range(1, t+1):
            n += 2
        return n
        