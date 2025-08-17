class Solution {
public:
    string interpret(string command) {
        string res = "", str;
        
        for (char n: command) {
            res += n;
            if (res == "G") {
                str += "G";
                res = "";
            } else if (res == "()") {
                str += "o";
                res = "";
            } else if (res =="(al)"){
                str += "al";
                res ="";
            }
        }
        return str;
    }
};