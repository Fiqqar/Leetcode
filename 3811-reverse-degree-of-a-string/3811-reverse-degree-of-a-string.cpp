class Solution {
public:
    int reverseDegree(string s) {
        int res = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            res += (i + 1) * ('z' - s[i] + 1);
        }
        return res;
    }
};