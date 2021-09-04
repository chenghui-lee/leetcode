class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> bucket(10001);
        for(auto x : nums){
            bucket[x] += x;
        }
        vector<int> dp(10001);
        dp[0] = bucket[0], dp[1] = bucket[1];
        for(int i=2; i<dp.size(); i++){
            dp[i] = max(dp[i-1], bucket[i] + dp[i-2]);
        }
        
        return dp[10000];
        
    }
};
