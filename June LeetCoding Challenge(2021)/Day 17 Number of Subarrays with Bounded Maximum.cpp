// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/discuss/117723/Python-standard-DP-solution-with-explanation
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int dp = 0, prev = -1, res = 0;
        
        for(int i=0; i<nums.size(); i++){
            if (nums[i] < left && i > 0){
                res += dp;
            }
            if (nums[i] > right){
                dp = 0;
                prev = i;
            }
            if (nums[i] >= left && nums[i] <= right){
                dp = i - prev;
                res += dp;
            }
        }
        return res;
    }
};
