class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        
        vector<unordered_map<long, int>> dp(n); // dp[i] = [diff, number of pairs with min length 2] ending at nums[i]
        int res = 0;
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                long diff = long(nums[i]) - long(nums[j]);
                int sum = 0;
                if (dp[j].count(diff)){
                    sum += dp[j][diff];
                }
                dp[i][diff] += sum + 1;
                res += sum;
            }
        }
        return res;
    }
};
