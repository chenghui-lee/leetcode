class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(auto& x : nums) x*=x;
        sort(nums.begin(), nums.end());
        return nums;
    }
};
