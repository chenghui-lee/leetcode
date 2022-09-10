class Solution {
public:
    /*
    At most k transactions, which means at most
    2*k buy + sell
    
    We can have a dp array that tracks all these buy and sell
    
    One observation is that we must begin with buy and end with sell 
    So our dp array can be [buy, sell, buy, sell, ...] states
    Where all the buy is even (0-indexed) and sell is odd.
    
    Initialise all buy with INT_MIN, sell with 0
    
    DP idea:
    
    Let j for looping the buy/sell transactions
    
    if j == 0, we need to max(skip, buy),
    dp[j] = max(dp[j], -price[i])
    
    if j % 2 == 1, we need to max(skip, sell)
    dp[j] = max(dp[j], dp[j-1] + price[i])
    
    if j % 2 == 0, we need to max(skip, buy)
    dp[j] = max(dp[j], dp[j-1] - price[i])
    
    All the transactions (0->j-1) are looped for all element inside the price array
    
    
    */
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0) return 0;
        int n = prices.size();
        vector<int> dp(2*k, 0);
        
        // initialise
        for(int i=0; i<dp.size(); i+=2){
            dp[i] = INT_MIN;
        }
        
        for(int i=0; i<prices.size(); i++){
            for(int j=0; j<dp.size(); j++){
                if (j==0){
                    dp[j] = max(dp[j], -prices[i]);
                }else if (j % 2 == 1){ // sell state
                    dp[j] = max(dp[j], dp[j-1] + prices[i]);
                }else if (j % 2 == 0){ // buy state
                    dp[j] = max(dp[j], dp[j-1] - prices[i]);
                }
            }
        }
        return dp.back();
        
    }
};
