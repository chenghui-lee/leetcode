class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int left = 0, right = 0, res = nums[0];
        int n = nums.size();
        for(int i=0; i<n; i++){
            left = (left == 0 ? 1 : left) * nums[i];
            right = (right == 0 ? 1 : right) * nums[n-1-i];
            res = max(res, max(left, right));
        }
        return res;
    }
};
