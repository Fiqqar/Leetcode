class Solution:
    def findWordsContaining(self, words: List[str], x: str) -> List[int]:
        res = []
        j = len(words)
        for i in range(j):
            if x in words[i]:
                res.append(i)
        return res

        