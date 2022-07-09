class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN); // max score gained when reaching i
        dp[0] = nums[0];
        multiset<int> s;
        s.insert(dp[0]);
        
        for(int i=1; i<n; i++){
            if (i > k){
                s.erase(s.find(dp[i - k - 1])); // erase those element where we cant reach current index
            }
            dp[i] = *rbegin(s) + nums[i]; // get the max score from the previous steps;
            s.insert(dp[i]);
        }
        
        return dp.back();
    }
};
