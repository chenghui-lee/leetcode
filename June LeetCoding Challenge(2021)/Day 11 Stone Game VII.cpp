class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefix(n+1);
        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i] + stones[i];
        }
        
        vector<vector<int>> dp(n, vector<int>(n)); // max abs diff btwn 2 player given stones i to j
        for(int len = 2; len <= n; len++){
            for(int i=0; i+len<=n; i++){
                int j = i + len - 1;
                dp[i][j] = max(prefix[j+1] - prefix[i+1] - dp[i+1][j], prefix[j] - prefix[i] - dp[i][j-1]);
                // dp[i][j] = max(take left, take right)
                // dp[i][j] = max(sum of array - A[i] - dp[i+1][j], sum of array - A[j] - dp[i][j-1])
            }
        }
        return dp[0][n-1];
    }
};
