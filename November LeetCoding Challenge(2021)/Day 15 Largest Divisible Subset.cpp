class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> prev(n, -1);
        vector<int> dp(n, 1); // length of subset of num[i]
        
        int longestIndex = 0, len = 1;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if (nums[i] % nums[j] == 0 && dp[j]+1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                    if (dp[i] > len){
                        len = dp[i];
                        longestIndex = i;
                    }
                }
            }
        }
        int idx = longestIndex;
        vector<int> res;
        while(idx != -1){
            res.push_back(nums[idx]);
            idx = prev[idx];
        }
        return res;
    }
};
