class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), maxCur = nums[0];
        int res = nums[0];
        for(int i=1; i<n; i++){
            maxCur = max(nums[i], maxCur + nums[i]); // start here, or join
            if (maxCur > res){
                res = maxCur;
            }
        }
        return res;
    }
};
