class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int res = 0, hold = prices[0];
        
        for(int i=1; i<n; i++){
            if (prices[i] < hold){
                hold = prices[i];
            }else{
                res = max(res, prices[i] - hold);
            }   
        }
        return res;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int res = 0, hold = INT_MAX;
        
        for(int i=0; i<n; i++){
            hold = min(hold, prices[i]);
            res = max(res, prices[i] - hold);
        }
        return res;
    }
};
