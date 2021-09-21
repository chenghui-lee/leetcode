class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, cur = 0;
        for(auto& x : nums){
            if (x == 0){
                cur = 0;
            }else{
                res = max(res, ++cur);
            }
        }
        return res;
    }
};
