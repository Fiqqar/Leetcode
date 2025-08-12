class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if (words.size() != s.size()) return false;
        for (size_t i = 0; i < words.size(); i++) {
            char w1 = words[i][0];
            if (w1 != s[i]) {
                return false;
            }
        }
        return true;
    }
};