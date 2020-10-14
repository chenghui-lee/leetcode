class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return max(nums[0], nums[1]);
        
        int a = helper(nums, 0, nums.size() - 2);
        int b = helper(nums, 1, nums.size() - 1);
        return max(a, b);
    }
    int helper(vector<int>& nums, int start, int end) {
        if (start == end) return nums[start];
        if (end - start == 1) return max(nums[start], nums[end]);
        
        vector<int> dp(end - start + 1, 0);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start+1]);
        
        for(int i=2; i<dp.size(); i++){
            dp[i] = max(dp[i-2] + nums[start + i], dp[i-1]);
        }
        return dp.back();
    } 
};
