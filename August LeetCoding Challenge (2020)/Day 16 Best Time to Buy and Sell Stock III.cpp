class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int firstBuy = INT_MIN, firstSell = 0, secondBuy = INT_MIN, secondSell = 0;
        
        for(int i=0; i<prices.size(); i++){
            firstBuy = max(firstBuy, -prices[i]);
            firstSell = max(firstSell, firstBuy + prices[i]);
            secondBuy = max(secondBuy, firstSell-prices[i]);
            secondSell = max(secondSell, secondBuy + prices[i]);
        }
        return secondSell;
    }
};
