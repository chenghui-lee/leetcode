/*

If got answer, the middle is equals to totalSum - x.
So the question become find longest subarray equals to (totalSum - x)
Then take the length of array - the result length.
Sliding window
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = -x, start = 0, end = 0;
        for(auto& x : nums) sum += x;
        
        if (sum < 0) return -1;
        else if (sum == 0) return nums.size();
        
        int cur = 0, res = INT_MIN;
        for(; end<nums.size(); end++){
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
