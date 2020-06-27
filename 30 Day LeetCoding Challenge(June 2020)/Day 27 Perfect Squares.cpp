// https://leetcode.com/problems/perfect-squares/discuss/71488/Summary-of-4-different-solutions-(BFS-DP-static-DP-and-mathematics)
class Solution {
public:
    int numSquares(int n) {
        if (n<=0) return 0;
        vector<int> dp(n+1, INT_MAX); //dp[i] = least number of perfect sqr nums sums up to i
        dp[0] = 0;
        for(int i=1; i<=n;i++){
            for(int j=1; j*j<=i; j++){
                dp[i] = min(dp[i], dp[i-j*j]+1); // for each num, it must be the sum of some number (i - j*j), where j*j is perfect sqr num
            }
        }
        return dp[n];
    }
};
