class Solution {
public:
    int quick(vector<int>& prices) {
        int val = 0;
        for(int i=1; i<prices.size(); i++){
            if (prices[i] > prices[i-1]){
                val += prices[i] - prices[i-1];
            }
        }
        return val;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        if (k==0 || prices.size() == 0) return 0;
        else if (prices.size()/2 <= k) return quick(prices); // becomes unlimited transactions
        
        vector<vector<int>> dp(k+1, vector<int>(prices.size(), 0)); // dp[i][j] = max profit at transaction i, j day
        
        for(int i=1; i<=k; i++){
            int balance = -prices[0];
            for(int j=1; j<prices.size(); j++){
                dp[i][j] = max(dp[i][j-1], balance + prices[j]); // sell = max(skip, bal + today price), sell is still considered as same transaction, so i no need - 1
                balance = max(balance, dp[i-1][j-1] - prices[j]); // buy = max(skip, previous trans profit - today price)
            }
        }
        return dp[k][prices.size()-1];
        
    }
    
};
