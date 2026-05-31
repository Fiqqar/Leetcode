class Solution {
public:
    int digitFrequencyScore(int n) {
        vector<int> freq(10,0);
        while(n > 0){
            int a = n % 10;
            n /= 10;
            freq[a]++;

        }
        int ct = 0;
        for(int i = 0;i < 10;i++){
            ct += i* freq[i];
        }
        return ct;
    }
};