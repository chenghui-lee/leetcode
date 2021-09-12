/*
[1,2,3,4,5,6,7]
when we let 3 as root, at left we have [1,2] and right [4,5,6,7]
so dp[3] = dp[2] * dp[4]

*/
class Solution {
public:
    int numTrees(int n) {
        if (n==0 || n==1) return 1;
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1; // 0 root or 1 root, we have 1 way of arranging it
      
        for(int i=2; i<=n; i++) { // total number of node
            for(int j=1; j<=i; j++) { // which node is root
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};
