class Solution {
public:
    string convert(const string& s, int numRows) {
        int n = (int)s.size();
        if (numRows == 1 || numRows >= n) return s;

        string result(n, '\0');
        char* __restrict out = &result[0];
        const char* __restrict in = s.data();

        const int cycleLen = 2 * numRows - 2;
        int idx = 0;

        for (int row = 0; row < numRows; ++row) {
            const int step1 = cycleLen - 2 * row;
            const bool hasDiagonal = (step1 > 0 && step1 < cycleLen);

            if (hasDiagonal) {
                for (int j = row; j < n; j += cycleLen) {
                    out[idx++] = in[j];
                    int d = j + step1;
                    if (d < n) out[idx++] = in[d];
                }
            } else {
                for (int j = row; j < n; j += cycleLen)
                    out[idx++] = in[j];
            }
        }
        return result;
    }
};