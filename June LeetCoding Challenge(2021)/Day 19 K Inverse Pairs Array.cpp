// https://leetcode.com/problems/k-inverse-pairs-array/discuss/1282496/Python-Short-O(nk)-solution-explained
// C++ modulus need to + MOD % MOD, because got negative val
class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<long>> dp(n+1, vector<long>(k+1, 1));
        vector<vector<long>> sum(n+1, vector<long>(k+1, 1));
        
        long MOD = 1e9 + 7;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=k; j++){
                if (j < i) dp[i][j] = sum[i-1][j];
                else dp[i][j] = (sum[i-1][j] - sum[i-1][j-i] + MOD) % MOD;
                sum[i][j] = (sum[i][j-1] + dp[i][j] + MOD) % MOD;
            }
        }
        return (dp[n][k] + MOD) % MOD;
    }
};
