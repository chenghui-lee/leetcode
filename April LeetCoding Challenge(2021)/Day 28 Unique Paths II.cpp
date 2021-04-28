class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = obstacleGrid[0][0] == 0?1:INT_MIN;
        for(int i=1; i<m; i++){
            if (obstacleGrid[i][0] == 1) dp[i][0] = INT_MIN;
            else{
                dp[i][0] = dp[i-1][0];
            }
        }
        for(int i=1; i<n; i++){
            if (obstacleGrid[0][i] == 1) dp[0][i] = INT_MIN;
            else{
                dp[0][i] = dp[0][i-1];
            }
        }
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if (obstacleGrid[i][j] == 1) dp[i][j] = INT_MIN;
                else{
                    dp[i][j] += max(dp[i-1][j], 0) +  max(dp[i][j-1], 0);
                }
            }
        }
        return max(dp[m-1][n-1], 0);
    }
};
