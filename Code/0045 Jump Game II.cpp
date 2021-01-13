class Solution {
public:
    int jump(vector<int>& nums) {
        int curEnd =0, curFurthest = 0, res = 0;
        
        for(int i=0; i<nums.size()-1; i++){
            curFurthest = max(curFurthest, nums[i] + i);
            if (curFurthest >= nums.size() - 1) return res + 1;
            if (i == curEnd){
                res++;
                curEnd = curFurthest;
            }
        }
        return res;
    }
};

// O(N^2) solution TLE on last test case
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        for(int i=0; i<n; i++) dp[i] = i;
        
        for(int i=0; i<n; i++){
            for(int j=1; j<=nums[i] && j+i<n; j++){
                dp[i+j] = min(dp[i+j], dp[i] + 1);
            }
        }
        return dp[n-1];
    }
};
