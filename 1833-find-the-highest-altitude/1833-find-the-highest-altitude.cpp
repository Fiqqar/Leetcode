class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr = 0;
        int highest = curr;
        int n = gain.size();

        for (int altGain : gain) {
            curr += altGain;
            highest = max(highest, curr);
        }
        return highest;
    }
};