// Solution 1: Use Longest Common Subsequence (LCS), will TLE
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int m = target.size(), n = arr.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        
         for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if (target[i-1] == arr[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return m - dp[m][n];
    }
};

// Solution 2: Use longest increasing subsequence (LIS) on the index of the arr in the target.
// Ignore those numbers which are not in the target array
// O(n) 592ms
class Solution {
public:
    
    int LIS(vector<int>& arr){
        vector<int> dp;
        for(auto& x : arr){
            auto it = lower_bound(dp.begin(), dp.end(), x);
            if (it == dp.end()) dp.push_back(x);
            else *it = x;
        }
        return dp.size();
    }
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> m; // num, index in target
        for(int i=0; i<target.size(); i++){
            m[target[i]] = i;
        }
        
        vector<int> temp;
        for(auto& x : arr){
            if(m.count(x)) temp.push_back(m[x]);
        }
        
        return target.size() - LIS(temp);
    }
};
