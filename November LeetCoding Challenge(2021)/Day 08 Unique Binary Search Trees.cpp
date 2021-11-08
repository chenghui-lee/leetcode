class Solution {
public:
    int numTrees(int n) {
        if (n == 0 || n == 1) return n;
        vector<int> dp(n+1, 0); // no of ways for i node
        dp[0] = dp[1] = 1;
        
        for(int i=2; i<=n; i++){ // num of node
            for(int j=1; j<=i; j++){ // which node is root
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};
