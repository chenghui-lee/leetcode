// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/discuss/117723/Python-standard-DP-solution-with-explanation
/*
A = [2, 1, 4, 2, 3], L = 2, R = 3

if A[i] < L
For example, i = 1. We can only append A[i] to a valid sub-array ending with A[i-1] to create new sub-array. So we have dp[i] = dp[i-1] (for i > 0)

if A[i] > R:
For example, i = 2. No valid sub-array ending with A[i] exist. So we have dp[i] = 0.
We also record the position of the invalid number 4 here as prev.


if L <= A[i] <= R
For example, i = 4. In this case any sub-array starts after the previous 
invalid number to A[i] (A[prev+1..i], A[prev+2..i]) is a new valid sub-array. So dp[i] += i - prev
*/
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int dp = 0, prev = -1, res = 0;
        
        for(int i=0; i<nums.size(); i++){
            if (nums[i] < left && i > 0){
                res += dp;
            }
            if (nums[i] > right){
                dp = 0;
                prev = i;
            }
            if (nums[i] >= left && nums[i] <= right){
                dp = i - prev;
                res += dp;
            }
        }
        return res;
    }
};
