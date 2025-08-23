class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i = 0, j = 0;
        int m = commands.size();

        for(int k = 0; k < m; k++) {
            if (commands[k][0] == 'R') {
                j++;
            }
            if (commands[k][0] == 'L') {
              j--;  
            }
            if (commands[k][0] == 'U') {
               i--; 
            }
            if (commands[k][0] == 'D') {
              i++;  
            }
        }
        return (i * n) + j;
    }
};