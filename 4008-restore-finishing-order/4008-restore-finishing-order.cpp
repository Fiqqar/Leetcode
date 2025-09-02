class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> res;
        unordered_map<int, int> mp;
        for (int& f : friends) {
            mp[f]++;
        }
        for (int i = 0; i < order.size(); i++) {
            if (mp.find(order[i]) != mp.end()) {
                res.push_back(order[i]);
            }
        }
        return res;
    }
};