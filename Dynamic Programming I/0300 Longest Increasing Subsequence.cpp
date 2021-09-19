class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for(int& x : nums){
            auto it = lower_bound(begin(dp), end(dp), x);
            if (it == dp.end()){
                dp.push_back(x);
            }else *it = x;
        }
        return dp.size();
    }
};
