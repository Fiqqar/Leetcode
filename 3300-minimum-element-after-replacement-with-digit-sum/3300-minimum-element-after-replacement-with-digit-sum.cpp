class Solution {
public:
    int minElement(vector<int>& nums) {
        int res = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            int curr = 0;
            while(nums[i] > 0){
                curr += nums[i] % 10;
                nums[i] /= 10;
            }
            nums[i] = curr;
            if(nums[i] < res) res = nums[i];
        }
        return res;
    }
};