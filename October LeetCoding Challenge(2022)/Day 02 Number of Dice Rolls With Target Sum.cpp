class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int MOD = 1e9 + 7;
        vector<vector<long>> dp(n+1, vector<long>(target+1, 0)); // given i dice, j val
        dp[0][0] = 1;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=target; j++){
                for(int face=1; face<=k; face++){ // each dice has k face
                    if (face <= j){
                        dp[i][j] += dp[i-1][j-face];
                        dp[i][j] %= MOD;
                    }
                }
            }
        }
        return dp[n][target] % MOD;

    }
};
