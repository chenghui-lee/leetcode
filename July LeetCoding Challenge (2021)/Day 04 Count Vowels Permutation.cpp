// https://leetcode.com/problems/count-vowels-permutation/discuss/398222/Detailed-Explanation-using-Graphs-With-Pictures-O(n)
class Solution {
public:
    int countVowelPermutation(int n) {
        int MOD = 1e9 + 7;
        vector<vector<long>> dp(n+1, vector<long>(5));
        // dp[i][j] = number of string with length i, ending at j-th char (a,e,i,o,u)
        
        // with length 1
        for(int i=0; i<5; i++){
            dp[1][i] = 1;
        }
        for(int i=1; i<n; i++){
            dp[i+1][0] = (dp[i][1] + dp[i][2] + dp[i][4]) % MOD; // a reachable from e,i,u
            dp[i+1][1] = (dp[i][0] + dp[i][2]) % MOD; // e from a and i
            dp[i+1][2] = (dp[i][1] + dp[i][3]) % MOD; // i from e and o
            dp[i+1][3] = dp[i][2]; // o from i
            dp[i+1][4] = (dp[i][2] + dp[i][3]) % MOD; // u from i and o
        }
        /*
        for (int i = 2; i <= n; i++) {
            dp[i][0] = (dp[i-1][4] + dp[i-1][1] + dp[i-1][2]) % MOD;
            dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;
            dp[i][2] = (dp[i-1][3] + dp[i-1][1]) % MOD;
            dp[i][3] = (dp[i-1][2]) % MOD;
            dp[i][4] = (dp[i-1][2] + dp[i-1][3]) % MOD;
        }
        */
        int res = 0;
        for(int i=0; i<5; i++){
            res = (res + dp[n][i]) % MOD;
        }
        return res;
    }
};
