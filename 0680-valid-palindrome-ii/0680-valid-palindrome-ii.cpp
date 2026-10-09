#include <cstdint>
#include <cstring>
#include <string>

class Solution {
    static inline std::uint64_t reverseBytes(std::uint64_t x) {
        x = ((x & 0x00FF00FF00FF00FFull) << 8)  | ((x >> 8)  & 0x00FF00FF00FF00FFull);
        x = ((x & 0x0000FFFF0000FFFFull) << 16) | ((x >> 16) & 0x0000FFFF0000FFFFull);
        return (x << 32) | (x >> 32);
    }

    static inline void skipMatching(const char* p, int& l, int& r) {
        while (r - l >= 7) {
            std::uint64_t head, tail;
            std::memcpy(&head, p + l, 8);
            std::memcpy(&tail, p + r - 7, 8);
            if (head != reverseBytes(tail)) break;
            l += 8;
            r -= 8;
        }
        while (l < r && p[l] == p[r]) { ++l; --r; }
    }

    static inline bool isPal(const char* p, int l, int r) {
        skipMatching(p, l, r);
        return l >= r;
    }

public:
    bool validPalindrome(const std::string& s) {
        const char* p = s.data();
        int l = 0, r = static_cast<int>(s.size()) - 1;
        skipMatching(p, l, r);
        return l >= r || isPal(p, l + 1, r) || isPal(p, l, r - 1);
    }
};