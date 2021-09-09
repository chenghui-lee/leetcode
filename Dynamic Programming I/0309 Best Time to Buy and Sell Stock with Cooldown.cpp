class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> rest(n); 
        vector<int> buy(n); 
        vector<int> sell(n); 
        
        buy[0] = -prices[0];
        for(int i=1; i<n; i++){
            rest[i] = max(rest[i-1], sell[i-1]); // rest or coming from prev sell
            buy[i] = max(rest[i-1] - prices[i], buy[i-1]); // buy or rest
            sell[i] = buy[i-1] + prices[i]; // sell
        }
        return max(rest[n-1], sell[n-1]);
        
    }
};

// O(1) space
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, rest = 0, sell = 0;
        for(auto cur : prices){
            int prev_sell = sell;
            sell = buy + cur; // sell the stock today
            buy = max(buy, rest - cur); // rest or buy the stock
            rest = max(rest, prev_sell); // rest or coming from prev sell
        }
        return max(rest, sell);
    }
};
