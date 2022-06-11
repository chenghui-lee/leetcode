/*
Idea, find the max size subarray such that the sum equals to sum_total - target

x x x [x x x] x x 


*/
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = -x, start = 0;
        for(auto& x : nums) sum += x;
        
        if (sum < 0) return -1;
        else if (sum == 0) return nums.size();
        
        int cur = 0, res = INT_MIN;
        for(int end = 0; end<nums.size(); end++){
            if(cur < sum){
                cur += nums[end];
            }
            while(cur>=sum){
                if (cur == sum){
                    res = max(res, end - start + 1);
                }
                cur -= nums[start++];
            }
            
        }
        return res==INT_MIN?-1:nums.size() - res;
    }
};
