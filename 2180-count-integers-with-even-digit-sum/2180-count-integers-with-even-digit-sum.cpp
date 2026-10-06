class Solution {
public:
    int count = 0;
    void yoCount(int x) {
        if (x < 10 && x % 2 == 0) {
            count++;
        } else {
            int sum = 0;
            while (x) {
                int d = x % 10;
                sum += d;
                x /= 10;
            }
            if (sum % 2 == 0) {
                count++;
            }
        }
    }
    int countEven(int num) {
        for (int i = 1; i <= num; i++) {
            yoCount(i);
        }
        return count;
    }
};