class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(m+1, 0)); // dp[i][j] = num of way given t[:i] and s[:j]
        
        for(int j=0; j<=m; j++){
            dp[0][j] = 1;
        } // if t is empty, dp[0][*] = 1
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                dp[i][j] = dp[i][j-1]; // take from prev s char
                if (t[i-1] == s[j-1]){
                    dp[i][j] += dp[i-1][j-1]; // take from prev s and t char
                }
            }
        }
        return dp[n][m];
        
    }
};
