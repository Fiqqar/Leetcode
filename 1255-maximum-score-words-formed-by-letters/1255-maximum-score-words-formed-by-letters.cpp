class Solution {
public:
    int maxScoreWords(std::vector<std::string>& words, std::vector<char>& letters,
                      std::vector<int>& score) {
        std::vector<int> avail(26, 0);
        for (char c : letters) avail[c - 'a']++;

        std::vector<std::vector<int>> counts(words.size());
        std::vector<int> wscore(words.size());
        for (int i = 0; i < words.size(); i++) {
            counts[i].assign(26, 0);
            for (char c : words[i]) counts[i][c - 'a']++;
            for (int j = 0; j < 26; j++)
                wscore[i] += counts[i][j] * score[j];
        }

        int best = 0;
        backtrack(words, counts, wscore, avail, 0, 0, best);
        return best;
    }

private:
    void backtrack(const std::vector<std::string>& words,
                   const std::vector<std::vector<int>>& counts,
                   const std::vector<int>& wscore,
                   std::vector<int>& avail,
                   int idx, int cur, int& best) {
        if (idx == words.size()) {
            best = std::max(best, cur);
            return;
        }
        backtrack(words, counts, wscore, avail, idx + 1, cur, best);

        bool canTake = true;
        for (int j = 0; j < 26; j++)
            if (counts[idx][j] > avail[j]) { canTake = false; break; }
        if (canTake) {
            for (int j = 0; j < 26; j++) avail[j] -= counts[idx][j];
            backtrack(words, counts, wscore, avail, idx + 1, cur + wscore[idx], best);
            for (int j = 0; j < 26; j++) avail[j] += counts[idx][j];
        }
    }
};