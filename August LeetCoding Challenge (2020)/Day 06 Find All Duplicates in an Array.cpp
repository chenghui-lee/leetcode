class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(auto x : nums){
            int index = abs(x)-1;
            if (nums[index] < 0) res.push_back(abs(x));
            nums[index] = -nums[index];
        }
        return res;
    }
};
