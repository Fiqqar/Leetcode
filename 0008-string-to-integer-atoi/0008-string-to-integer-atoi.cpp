class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0, n = s.size();

        while (i < n && s[i] == ' ') i++;

        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        long result = 0;
        const long limit = -(long)INT_MIN;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            result = result * 10 + (s[i] - '0');
            if (result > limit) {
                result = limit;
                break;
            }
            i++;
        }

        result *= sign;
        if (result < INT_MIN) return INT_MIN;
        if (result > INT_MAX) return INT_MAX;
        return static_cast<int>(result);
    }
};