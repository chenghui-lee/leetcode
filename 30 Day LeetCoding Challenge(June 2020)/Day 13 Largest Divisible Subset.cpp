class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return nums;
        sort(nums.begin(), nums.end());
        vector<int> dp(n,1); // number of subset at position i, counting from index 0 to i
        vector<int> prev(n,-1); // to record the last previous index, where element i % element j == 0
        
        int longestIndex = 0;
        int len = 0;
        
        for (int i=1; i<n;i++){
            for (int j=0;j<i;j++){
                if (nums[i]%nums[j] == 0 && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    prev[i] = j;
                    
                    if (dp[i] > len){
                        len  = dp[i];
                        longestIndex = i;
                    }
                }
            }
        }
        
        int index = longestIndex;
        vector<int> result;
        while(index != -1){ // going back from the rightmost longest subset element, back to the front
            result.push_back(nums[index]);
            index = prev[index];
        }
        return result;
    }
};
