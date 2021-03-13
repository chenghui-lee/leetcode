class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, long> dp; // number of trees with root i
        long MOD = 1e9 + 7;
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<arr.size(); i++){
            dp[arr[i]] = 1;
            for(int j=0; j<i ;j++){
                if (arr[i] % arr[j] == 0 && dp.count(arr[i]/arr[j])){
                    dp[arr[i]] += (dp[arr[j]]*dp[arr[i]/arr[j]]) % MOD;
                }
            }
        }
        long res = 0;
        for(int i=0; i<arr.size(); i++){
            res += dp[arr[i]];
        }
        return res % MOD;
    }
};
