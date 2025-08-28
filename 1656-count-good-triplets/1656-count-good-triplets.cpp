class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
         int n = arr.size(), ans = 0;

        for (int j = 1; j < n - 1; ++j) {
            vector<int> left, right;

            for (int i = 0; i < j; ++i)
                if (abs(arr[i] - arr[j]) <= a)
                    left.push_back(arr[i]);

            for (int k = j + 1; k < n; ++k)
                if (abs(arr[j] - arr[k]) <= b)
                    right.push_back(arr[k]);

            sort(right.begin(), right.end());

            for (int arrJ : left) {
                int low = arrJ - c;
                int high = arrJ + c + 1;
                ans += lower_bound(right.begin(), right.end(), high) -
                       lower_bound(right.begin(), right.end(), low);} }

        return ans;
    }
};