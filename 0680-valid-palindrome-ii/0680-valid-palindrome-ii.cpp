class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                int l = left + 1, r = right;

                while (l < r && s[l] == s[r]) {
                    ++l;
                    --r;
                }

                if (l >= r) return true;

                l = left;
                r = right - 1;

                while (l < r && s[l] == s[r]) {
                    ++l;
                    --r;
                }

                return l >= r;
            }

            ++left;
            --right;
        }

        return true;
    }
};