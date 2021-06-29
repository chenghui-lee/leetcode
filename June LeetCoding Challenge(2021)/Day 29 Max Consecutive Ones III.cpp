/*
If one, expand windows

If zero, increment count.
If count <= k, expand
Else, move i forward, check zero count

*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), i = 0, j = 0;
        int count = 0; // count of zero in windows
        int res = 0;
        
        while(i < n && j < n){
            if (nums[j] == 1 && count <= k){
                res = max(res, j-i+1);
            }else{
                if (nums[j] == 0) count++;
                if (count <= k){
                    res = max(res, j-i+1);
                }else{
                    if(nums[i] == 0) count--;
                    i++;
                }
            }
            j++;
        }
        return res;
    }
};
