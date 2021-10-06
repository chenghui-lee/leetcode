class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int x : nums){
            int idx = abs(x) - 1;
            if (nums[idx] < 0) res.push_back(abs(x));
            nums[idx] *= -1;
        }
        return res;
    }
};
