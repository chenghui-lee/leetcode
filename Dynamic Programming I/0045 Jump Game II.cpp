class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, n);
        dp[0] = 0;
        
        for(int i=0; i<n; i++){
            for(int j=i; j<n && j<=i + nums[i]; j++){
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }
        return dp[n-1];
    }
};

// O(n) solution
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int curEnd = 0, curFurthest = 0, res = 0;
        
        for(int i=0; i<n-1; i++){
            curFurthest = max(curFurthest, i + nums[i]);
            if (curEnd == i){
                res++;
                curEnd = curFurthest;
            }
        }
        
        return res;
    }
};
