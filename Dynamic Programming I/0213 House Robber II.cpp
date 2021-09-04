class Solution {
public:
    int helper(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        vector<int> dp(n);
        dp[0] = nums[start], dp[1] = max(nums[start], nums[start+1]);
        
        for(int i=2; i<n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[start+i]);
        }
        return dp[n-1];
        
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3){
            int mx = 0;
            for(auto x : nums){
                mx = max(mx, x);
            }
            return mx;
        }
        
        int a = helper(nums, 0, n-2);
        int b = helper(nums, 1, n-1);
        return max(a, b);
    }
};
