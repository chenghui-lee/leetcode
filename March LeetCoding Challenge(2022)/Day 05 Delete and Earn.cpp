class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> cnt(10001, 0);
        
        for(int x : nums){
            cnt[x] += x;
        }
        vector<int> dp(10001, 0);
        dp[0] = cnt[0], dp[1] = cnt[1];
        for(int i=2; i<dp.size(); i++){
            dp[i] = max(dp[i-1], cnt[i] + dp[i-2]);
        }
        return dp[10000];
    }
};
