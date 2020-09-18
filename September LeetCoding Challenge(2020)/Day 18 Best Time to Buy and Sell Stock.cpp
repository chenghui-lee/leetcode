class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int minGlobal = INT_MAX;
        for(int i=0; i<prices.size(); i++){
            if(prices[i] < minGlobal){
                minGlobal = prices[i];
            } else if (prices[i] - minGlobal > res){
                res = prices[i] - minGlobal;
            }
        }
        return res;
    }
};
