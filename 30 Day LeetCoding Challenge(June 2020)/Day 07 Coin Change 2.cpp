class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0));
        for (int i=0;i<=coins.size();i++){ // when the amount is zero
            dp[i][0] = 1;
        }
        for (int row=1; row<=coins.size();row++){
            for (int col=1;col<=amount;col++){
                int y;
                if (col>=coins[row-1]) y = dp[row][col-coins[row-1]]; // coins[row-1] is the current coin
                else y =0;
                dp[row][col] = dp[row-1][col] + y;
                // dp[row][col] = w/o using this coin + use this coin
            }
        }
        return dp[coins.size()][amount];
    }
};
