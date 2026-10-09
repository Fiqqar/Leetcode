
#include <string>
using namespace std;

class Solution {
    static inline bool isPal(const char* s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            ++l;
            --r;
        }
        return true;
    }

public:
    bool validPalindrome(const string& s) {
        const char* p = s.data();
        int l = 0;
        int r = static_cast<int>(s.size()) - 1;

        while (l < r && p[l] == p[r]) {
            ++l;
            --r;
        }

        return l >= r ||
               isPal(p, l + 1, r) ||
               isPal(p, l, r - 1);
    }
};