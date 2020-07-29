class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = INT_MIN, cooldown = 0, sell = 0;
        for(auto x : prices){
            int prev_sell = sell;
            hold = max(hold, cooldown - x);
            cooldown = max(cooldown, prev_sell);
            sell = hold + x;
        }
        return max(sell, cooldown);
    }
};
