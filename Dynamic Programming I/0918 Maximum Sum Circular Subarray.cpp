class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int minCur = 0, minGlobe = INT_MAX;
        int maxCur = 0, maxGlobe = INT_MIN;
        
        for(int i=0; i<n; i++){
            minCur = min(minCur + nums[i] , nums[i]);
            minGlobe = min(minGlobe, minCur);
            maxCur = max(maxCur + nums[i], nums[i]);
            maxGlobe = max(maxGlobe, maxCur);
        }
        if (sum == minGlobe) return maxGlobe;
        return max(maxGlobe, sum - minGlobe);
    }
};
