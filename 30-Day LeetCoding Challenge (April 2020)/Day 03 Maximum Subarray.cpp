class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxCurrent,maxGlobal;
        maxCurrent = maxGlobal = nums[0];
        if (nums.size() > 1){
            for (int i=1; i<nums.size(); i++){
                maxCurrent = max(nums[i], nums[i] + maxCurrent);
                if (maxCurrent > maxGlobal){
                    maxGlobal = maxCurrent;
                }
            }
        }
        return maxGlobal;
    }
};
