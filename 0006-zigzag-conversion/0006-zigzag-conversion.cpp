class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (numRows == 1 || numRows >= n) return s;

        string result;
        result.reserve(n);

        int cycleLen = 2 * numRows - 2;

        for (int row = 0; row < numRows; ++row) {
            for (int j = row; j < n; j += cycleLen) {
                result += s[j];
                if (row != 0 && row != numRows - 1) {
                    int diag = j + cycleLen - 2 * row;
                    if (diag < n) result += s[diag];
                }
            }
        }
        return result;
    }
};