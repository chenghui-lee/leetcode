class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int maxRow = 100;
        vector<vector<double>> dp(maxRow, vector<double>(maxRow, 0));
        // dp[i][j] = max water jar i,j can hold
        
        dp[0][0] = poured;
        for(int i=0; i<maxRow-1; i++){
            for(int j=0; j<=i; j++){
                double balance = (dp[i][j] - 1) / 2.0;
                if (balance > 0){
                    dp[i+1][j] += balance;
                    dp[i+1][j+1] += balance;
                }
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
};
