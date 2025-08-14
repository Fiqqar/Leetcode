class Solution {
public:
    string toLowerCase(string s) {
        for (char& w : s) {
            w = tolower(w);
        }
        return s;
    }
};