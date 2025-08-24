class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        if( n == 0 )return true;
        if(m == 1){
            if(flowerbed[0] == 0) return true;
            return false;
        }

        for( int i = 0; i<m;i++){
            if( flowerbed[i] == 0){
                bool left = (i == 0) || (flowerbed[i - 1] == 0);
                bool right = (i == m - 1) || (flowerbed[i + 1] == 0);
                if (left && right)
                {
                    n--;
                    if(n==0) return true;
                    i++; 
                }                     
            }
        }
        return false;
    }
};