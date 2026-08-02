class Solution {
public:
    string intToRoman(int num) {
        static const char* thou[] = {"", "M", "MM", "MMM"};
        static const char* hund[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        static const char* tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        static const char* ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        return string(thou[num / 1000]) + hund[num % 1000 / 100]
             + tens[num % 100 / 10] + ones[num % 10];
    }
};