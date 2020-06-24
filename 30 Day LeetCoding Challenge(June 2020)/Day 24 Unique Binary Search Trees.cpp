//https://leetcode.com/problems/unique-binary-search-trees/discuss/31666/DP-Solution-in-6-lines-with-explanation.-F(i-n)-G(i-1)-*-G(n-i)
class Solution {
public:
    int numTrees(int n) {
        if (n==0 || n==1) return 1;
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1; // 0 root or 1 root, we have 1 way of arranging it
        for(int i=2; i<=n; i++) {
            for(int j=1; j<=i; j++) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};
