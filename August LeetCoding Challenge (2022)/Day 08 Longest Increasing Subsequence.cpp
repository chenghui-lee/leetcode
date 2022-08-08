class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        // for every x in num, insert it if larger than all element. else replace the lower bound of that num
        for(int x : nums){
            auto it = lower_bound(dp.begin(), dp.end(), x);
            if (dp.size() ==0 || it == dp.end()){
                dp.push_back(x);
            }else{
                *it = x;
            }
        }
        
        return dp.size();
    }
};
