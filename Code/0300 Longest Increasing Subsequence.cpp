// Method 1, DP
// O(N^2)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        
        int res = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if (nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};


// Method 2, Patience Sorting
// O(NlogN)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        int size = 0;
        
        for(int& x : nums){
            int i = 0, j = size;
            while(i < j){
                int mid = (i+j)/2;
                if (dp[mid] < x) i = mid + 1;
                else j = mid;
            }
            dp[i] = x;
            if (i == size)size++;
        }
        return size;
        
        
    }
};
