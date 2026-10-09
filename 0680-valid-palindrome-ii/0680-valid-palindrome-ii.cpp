class Solution {
    static bool isPal(const char* d, size_t l, size_t r) {
        while (l < r) {
            if (d[l++] != d[r--]) return false;
        }
        return true;
    }

public:
    bool validPalindrome(const string& s) {
        size_t n = s.size();
        if (n < 2) return true;
        const char* d = s.data();
        size_t l = 0, r = n - 1;

        while (l < r && d[l] == d[r]) {
            ++l;
            --r;
        }

        return l >= r ||
               isPal(d, l + 1, r) ||
               isPal(d, l, r - 1);
    }
};