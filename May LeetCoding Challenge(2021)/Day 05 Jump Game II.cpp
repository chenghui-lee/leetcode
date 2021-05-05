class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n, 1e9); // steps needed to reach i-th place
        dp[0] = 0;
        for(int i=0; i<n; i++){
            for(int j=1; j+i<n && j<=nums[i]; j++){
                dp[i+j] = min(dp[i+j], dp[i] + 1);
            }
        }
        return dp[n-1];
    }
};
