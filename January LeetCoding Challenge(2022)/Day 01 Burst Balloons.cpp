class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0)); // dp[i][j] = maxCoin in (nums[i] ~ nums[j])
        
        for(int len=1; len<=n; len++){ // how many balloons in range
            for(int i = 1; i<= n-len+1; i++){ // starting point
                int j = i + len - 1; // ending point
                for(int stay=i; stay<=j; stay++){ // select which one to be the last to burst
                    dp[i][j] = max(dp[i][j], dp[i][stay-1] + nums[i-1]*nums[stay]*nums[j+1] + dp[stay+1][j]);
                    // maxCoin from left partition + balloon before left * selected balloon * balloon after right + maxCoin from right partition
                }
            }
    
        }
        return dp[1][n];
    }
};
