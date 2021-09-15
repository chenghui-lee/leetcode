class Solution {
public:
    int sumRange(vector<vector<int>>& dp, int row1, int col1, int row2, int col2){
        return dp[row2+1][col2+1] - dp[row2+1][col1] - dp[row1][col2+1] + dp[row1][col1];
    }
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        
        // calc origin sum
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1] - dp[i][j] + mat[i][j]; 
            }
        }
        // calc block sum
        vector<vector<int>> res(m, vector<int>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int row1 = max(0, i-k), col1 = max(0, j-k);
                int row2 = min(m-1, i+k), col2 = min(n-1, j+k);
                res[i][j] = sumRange(dp, row1, col1, row2, col2);
            }
        }
        return res;
    }
};
