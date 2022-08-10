class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, long> dp; // number of trees with root i, which dp[x] = dp[i] * dp[j], where i and j must be <= x
        // so we need to sort the array
        long MOD = 1e9 + 7;
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<arr.size(); i++){
            dp[arr[i]] = 1;
            for(int j=0; j<i ;j++){
                int num = arr[i] / arr[j];
                if (arr[i] % arr[j] == 0 && dp.find(num) != dp.end()){
                    dp[arr[i]] += (dp[arr[j]]*dp[num]) % MOD;
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
