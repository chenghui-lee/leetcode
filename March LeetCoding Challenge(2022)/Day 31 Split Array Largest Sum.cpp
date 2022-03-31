// binary search to find the value C, where C is the max sum
// for each trial, we will check the number of groups required to get C
class Solution {
public:
    bool verify(vector<int>& nums, long maxSumAllowed, int m){
        long curSum = 0, grp = 1;
        
        for(int x : nums){
            if (curSum + x <= maxSumAllowed){
                curSum += x;
            }else{
                curSum = x; // end the previous group, starts here
                grp++;
                if (grp > m) return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        long sum = 0, mx = 0;
        for(int x : nums){
            mx = max(mx, (long)x);
            sum += x;
        }
        long low = mx, high = sum;
        
        while(low <= high){
            long mid = low + (high - low) / 2;
            if (verify(nums, mid, m)){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return (int) low;
    }
};
