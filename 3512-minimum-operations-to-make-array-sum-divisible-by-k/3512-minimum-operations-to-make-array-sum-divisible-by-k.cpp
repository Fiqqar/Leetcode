class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count = accumulate(nums.begin(), nums.end(), 0);
        return count % k;
    }
};