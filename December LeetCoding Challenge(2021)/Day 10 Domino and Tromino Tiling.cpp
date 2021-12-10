class Solution {
public:
    // credit: https://www.youtube.com/watch?v=S-fUTfqrdq8
    int numTilings(int n) {
        int MOD = 1e9 + 7;
        if (n <= 2) return n;
        vector<vector<long>> dp(n+1, vector<long>(2, 0)); 
        // dp[i][0] = num of ways to fill until fist i col, with both rows occupied
        // dp[i][1] = num of ways to fill until first i col, with either row occupied
        dp[0][0] = dp[1][0] = 1;
        
        for(int i=2; i<=n; i++){
            dp[i][0] = (dp[i-1][0] + dp[i-2][0] + 2 * dp[i-1][1]) % MOD;
            /*
            
            xx+ = xx+  +  x++  + xx+ +  x++
            xx+   xx+     x++    x++    xx+
            
            */
            dp[i][1] = (dp[i-1][1] + dp[i-2][0]) % MOD;
        }
        return dp[n][0];
    }
};
