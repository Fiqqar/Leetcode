class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        
        for(int i = 0; i < s.length(); i++){
            unordered_map<int,int> m;
            int len = 0;
            
            for(int j = i; j < s.length(); j++){
                if(m[s[j]] == 1){
                    break;
                }
                
                len++;
                maxlen = max(maxlen, len);
                m[s[j]] = 1;
            }
        }
        
        return maxlen;
    }
};