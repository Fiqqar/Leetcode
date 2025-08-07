class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        i = n // m
        return n * (n + 1) // 2 - i * (i + 1) * m
        