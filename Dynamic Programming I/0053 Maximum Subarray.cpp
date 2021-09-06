class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxCur = nums[0], maxGlobe = nums[0];
        
        for(int i=1; i<n; i++){
            maxCur = max(nums[i], maxCur + nums[i]); // take new, or join
            if (maxCur > maxGlobe){
                maxGlobe = maxCur;
            }
        }
        return maxGlobe;
    }
};
