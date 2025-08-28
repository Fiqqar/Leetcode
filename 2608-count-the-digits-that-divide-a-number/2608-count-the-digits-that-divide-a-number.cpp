class Solution {
public:
    int countDigits(int num) {
        int res = 0;
        int temp = num;

        while (temp > 0) {
            int ans = temp % 10;
            if (ans > 0 && num % ans == 0) {
                res++;
            }
            temp /= 10;
        }
        return res;

    }
};