class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool res = false;
        long rem = 1;

        if (n == 1) {
            res = true;
        } else {
            while ( n > rem) {
                rem = rem * 2;
            }
            if ( rem == n) {
                res = true;
            }
        }
        return res;
    }
};