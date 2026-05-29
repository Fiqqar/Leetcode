class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int sum=0,idx=0;
        for(auto num : nums) {
            if(idx%2==0) {
                sum+=num;
            }
            else {
                sum-=num;
            }
            idx++;
        }
        return sum;
    }
};