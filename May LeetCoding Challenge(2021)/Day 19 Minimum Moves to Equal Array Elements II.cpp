class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size(), res = 0;
        auto it = nums.begin() + n/2;
        nth_element(nums.begin(), it, nums.end()); // this will make n/2-th element at it place, 
      // others may varies. but left side is smaller and right side is larger
        int median = *it;
        
        for(auto x : nums){
            res += abs(x-median);
        }
        return res;
    }
};
