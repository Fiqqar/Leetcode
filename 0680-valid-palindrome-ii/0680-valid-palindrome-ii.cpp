#include <cstdint>
#include <cstring>
#include <string>

#if defined(__GNUC__) || defined(__clang__)
#define PAL680_ALWAYS_INLINE __attribute__((always_inline)) inline
#else
#define PAL680_ALWAYS_INLINE inline
#endif

class Solution {
    static PAL680_ALWAYS_INLINE std::uint64_t reverseBytes(std::uint64_t x) {
        x = ((x & 0x00FF00FF00FF00FFull) << 8) |
            ((x >> 8) & 0x00FF00FF00FF00FFull);
        x = ((x & 0x0000FFFF0000FFFFull) << 16) |
            ((x >> 16) & 0x0000FFFF0000FFFFull);
        return (x << 32) | (x >> 32);
    }

    static PAL680_ALWAYS_INLINE void skipMatching(const char* p, int& l, int& r) {
        if (l < r && p[l] != p[r]) return;

        while (r - l >= 31) {
            std::uint64_t h0, t0, h1, t1, h2, t2, h3, t3;
            std::memcpy(&h0, p + l, 8);
            std::memcpy(&t0, p + r - 7, 8);
            if (h0 != reverseBytes(t0)) break;

            std::memcpy(&h1, p + l + 8, 8);
            std::memcpy(&t1, p + r - 15, 8);
            if (h1 != reverseBytes(t1)) { l += 8; r -= 8; break; }

            std::memcpy(&h2, p + l + 16, 8);
            std::memcpy(&t2, p + r - 23, 8);
            if (h2 != reverseBytes(t2)) { l += 16; r -= 16; break; }

            std::memcpy(&h3, p + l + 24, 8);
            std::memcpy(&t3, p + r - 31, 8);
            if (h3 != reverseBytes(t3)) { l += 24; r -= 24; break; }

            l += 32;
            r -= 32;
        }

        while (r - l >= 7) {
            std::uint64_t head, tail;
            std::memcpy(&head, p + l, 8);
            std::memcpy(&tail, p + r - 7, 8);
            if (head != reverseBytes(tail)) break;
            l += 8;
            r -= 8;
        }

        while (l < r && p[l] == p[r]) {
            ++l;
            --r;
        }
    }

    static PAL680_ALWAYS_INLINE bool isPal(const char* p, int l, int r) {
        skipMatching(p, l, r);
        return l >= r;
    }

public:
    bool validPalindrome(const std::string& s) {
        const char* p = s.data();
        int l = 0, r = static_cast<int>(s.size()) - 1;
        skipMatching(p, l, r);
        return l >= r ||
               isPal(p, l + 1, r) ||
               isPal(p, l, r - 1);
    }
};