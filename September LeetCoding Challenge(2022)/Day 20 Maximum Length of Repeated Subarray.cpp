class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        // dp[i][j] = longest common prefix of A[:i] and B[:j]
        int res = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (nums1[i] == nums2[j]){
                    dp[i+1][j+1] = dp[i][j] + 1;
                    res = max(res, dp[i+1][j+1]);
                }
            }
        }
        
        return res;
    }
};
