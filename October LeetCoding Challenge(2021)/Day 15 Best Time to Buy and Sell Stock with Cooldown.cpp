class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(n, 0), sell(n, 0), rest(n, 0);
        buy[0] = -prices[0];
        
        for(int i=1; i<n; i++){
            rest[i] = max(rest[i-1], sell[i-1]); // rest or coming fron prev sell
            buy[i] = max(rest[i-1] - prices[i], buy[i-1]); // buy or rest
            sell[i] = buy[i-1] + prices[i];
        }
        
        return max(sell[n-1], rest[n-1]);
    }
};
