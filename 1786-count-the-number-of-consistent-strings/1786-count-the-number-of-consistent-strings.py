class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        n = list(allowed)
        m = 0
        for i in words:
            if set(i).issubset(n):
                m += 1
        return m
