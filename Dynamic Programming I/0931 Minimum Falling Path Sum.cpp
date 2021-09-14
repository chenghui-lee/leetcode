class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp = matrix;
        
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int choice = dp[i-1][j];
                if (j-1 >= 0) choice = min(choice, dp[i-1][j-1]);
                if (j+1 < n) choice = min(choice, dp[i-1][j+1]);
                dp[i][j] += choice;
            }
        }
        int res = INT_MAX;
        for(auto x : dp[n-1]) res = min(res, x);
        return res;
    }
};
