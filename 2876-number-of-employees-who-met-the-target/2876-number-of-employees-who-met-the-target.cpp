class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int l = hours.size();
        int n = 0;

        for (int i = 0; i < l; i++) {
            if(hours[i] >= target){
                n++;
            }
        }
        return n;
    }
};