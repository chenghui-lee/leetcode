/*
dp[i][2]; // max profit i can get on i-th day, 0 means no stock on hand, 1 means holding

Case 1: Have stock on hand (1) -> How to get to this state?
- Buy it today -> dp[i][1] = dp[i-1][0] - price[i] - fee
- Bought it previous day -> dp[i][1] = dp[i-1][1]

Case 2: Have no stock in hand (0)
- Sell it already -> dp[i][0] = dp[i-1][1] + price[i]
- Have no stock from the previous day -> dp[i][0] = dp[i-1][0]

*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][1] = -prices[0]-fee;
        
        for(int i=1; i<n; i++){
            dp[i][1] = max(dp[i-1][0] - prices[i] - fee, dp[i-1][1]);
            dp[i][0] = max(dp[i-1][1] + prices[i], dp[i-1][0]);
        }
        return dp[n-1][0];
        
    }
};
