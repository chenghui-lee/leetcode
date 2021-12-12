// https://leetcode.com/problems/partition-equal-subset-sum/discuss/90592/01-knapsack-detailed-explanation
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // this is a knapsack problem
        // we want to check whether given a set of numbers, can we sum to the target (sum/2)
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        sum /=2;
        // dp[i] = can we sum to i
        vector<bool> dp(sum+1, false);
        dp[0] = true; // sum to 0
        
        for(auto num : nums){
            for(int i=sum; i>0; i--){
                if (i >= num) {
                    dp[i] = dp[i] || dp[i-num];
                }
            }
        }
        return dp[sum];
        
    }
};
