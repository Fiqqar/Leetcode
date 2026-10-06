class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<int> freq(51, 0);
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        int ans = 0;
        for (int i = 1; i < 51; i++) {
            if (freq[i] != 0 && freq[i] % 2 == 0) {
                ans = ans^i;
            }
        }
        return ans;
    }
};