class Solution {
public:
    int numberOfMatches(int n) {
        int total = 0;

        while (n != 1) {
            int count = n / 2;
            int extra = n % 2;

            total += count;
            n = count + extra;
        }
        return total;
    }
};