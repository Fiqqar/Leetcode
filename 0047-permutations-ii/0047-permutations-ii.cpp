class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        backtrack(nums, 0, res);
        return res;
    }

private:
    void backtrack(std::vector<int>& nums, int start, std::vector<std::vector<int>>& res) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }
        std::unordered_set<int> seen;
        for (int i = start; i < nums.size(); i++) {
            if (seen.count(nums[i])) continue;
            seen.insert(nums[i]);
            std::swap(nums[start], nums[i]);
            backtrack(nums, start + 1, res);
            std::swap(nums[start], nums[i]);
        }
    }
};