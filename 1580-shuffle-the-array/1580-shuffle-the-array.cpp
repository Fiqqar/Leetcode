class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        int a = 0;

        for (int i = 0; i < n; i++) {
            res.push_back(nums[a]);
            res.push_back(nums[a + n]);
            a++;
        }
        return res;
    }
};