class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int left = 0, right = 0, res = nums[0];
        int n = nums.size();
        // if there is no 0 in the array, the result will be starting from leftmost / rightmost.
        // if there is zero, then we start from somewhere middle
        for(int i=0; i<n; i++){
            // if prev has zero, we take the curr one as starting point
            left = (left == 0 ? 1 : left) * nums[i];
            right = (right == 0 ? 1 : right) * nums[n-1 -i];
            res = max(res, max(left, right));
        }
        return res;
    }
};
