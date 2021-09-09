class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = -prices[0], sell = 0;
        
        for(int i=1; i<prices.size(); i++){
            int prev_sell = sell;
            sell = max(sell, buy + prices[i] - fee); // do nothing or sell
            buy = max(buy, prev_sell - prices[i]); // do nothing or buy
        }
        return sell;
    }
};
