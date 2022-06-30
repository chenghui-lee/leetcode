class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), res = 0;
        auto it = nums.begin() + n/2;
        nth_element(nums.begin(), it, nums.end());
        int median = *it;
        
        for(auto x : nums){
            res += abs(x-median);
        }
        return res;
    }
};
