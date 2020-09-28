class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1 || nums.size() == 0) return 0;
        int product = 1, left = 0, right = 0;
        int res = 0;
        
        while(right < nums.size()){
            product *= nums[right];
            while(product >= k){
                product /= nums[left];
                left++;
            }
            res += right - left + 1; // new subarray size = num of elements
            right++;
        }
        return res;
    }
};
