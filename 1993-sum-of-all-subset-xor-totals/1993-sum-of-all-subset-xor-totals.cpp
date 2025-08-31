class Solution {
public:
    int subsetXORSum(vector<int>& nums, int i = 0, int sum = 0) {
        return (i == nums.size()) ? sum : subsetXORSum(nums, i+1, sum^nums[i])+subsetXORSum(nums, i+1, sum);
    }
};