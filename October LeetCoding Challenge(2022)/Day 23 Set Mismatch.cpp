class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2);
        for(auto x : nums){
            if (nums[abs(x)-1] < 0) res[0] = abs(x);
            else nums[abs(x)-1] *= -1;
        }
        for (int i=0;i<nums.size();i++) {
            if (nums[i] > 0) res[1] = i+1;
        }
        return res;
    }
};
