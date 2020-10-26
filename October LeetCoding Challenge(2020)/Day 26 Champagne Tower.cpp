class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        const int maxRow = 100;
        vector<vector<double>> dp(maxRow, vector<double>(maxRow, 0)); // dp[i][j] = total amount of champagne glass[i][j] can hold
        dp[0][0] = poured; // let 1st class hold all of the volume
        
        for(int i=0; i<maxRow - 1; i++){
            for(int j=0; j<=i; j++){
                double extra = (dp[i][j] - 1) / 2.0;
                if (extra > 0){ // if got extra then only distribute to lower row
                    dp[i+1][j] += extra; 
                    dp[i+1][j+1] += extra;
                }
                
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
};
