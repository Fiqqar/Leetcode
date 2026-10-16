class Solution {
public:
    void dfs(vector<string>& temp, vector<string>& temp1) {
        vector<string> next;
        for (string s : temp) {
            for (string t : temp1) {
                next.push_back(s + t);
            }
        }

        temp = next;
    }


    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if (n == 0)
            return {};
        vector<string> temp;

        string mp[] = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        for (char c : mp[digits[0] - '0'])
            temp.push_back(string(1, c));

        for (int i = 1; i < n; i++) {
            vector<string> temp1;

            for (char c : mp[digits[i] - '0'])
                temp1.push_back(string(1, c));

            dfs(temp, temp1);
        }

        return temp;
    }
};