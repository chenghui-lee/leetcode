class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        
        sum /= 2;
        int n = nums.size();
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1)); // dp[i][j] = sum of i-th element to j
        
        dp[0][0] = true;
        for(int i=1; i<=n; i++){
            dp[i][0] = true;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                dp[i][j] = dp[i-1][j];
                if (j >= nums[i-1]){
                    dp[i][j] = (dp[i][j] || dp[i-1][j-nums[i-1]]);
                }
            }
        }
        return dp[n][sum];
    }
};
