// dp, O(n*k), TLE 57/65
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> dp(n, INT_MIN);
        dp[0] = nums[0];
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j-i<=k && j<n; j++){
                dp[j] = max(dp[j], dp[i] + nums[j]);
            }
        }
        return dp[n-1];
    }
};

// deque
// https://leetcode.com/problems/jump-game-vi/discuss/978462/C%2B%2B-DP-%2B-Monoqueue-O(n)

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        
        for(int i=0; i<n; i++){
            int max = dq.empty()? 0 : nums[dq.front()];
            nums[i] = nums[i] + max;
            
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            while(!dq.empty() && i - dq.front() + 1 > k) dq.pop_front();
        }
        return nums[n-1];
    }
};
