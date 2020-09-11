class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int prefix = 0, suffix = 0, res = nums[0];
        for(int i=0; i<nums.size(); i++){
            prefix = (prefix ? prefix : 1) * nums[i];
            suffix = (suffix ? suffix : 1) * nums[nums.size() - 1 - i];
            res = max(res, max(prefix, suffix));
        }
        return res;
    }
};
