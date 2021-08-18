class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n==1 && s[0] != '0') return 1;
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = s[0]=='0'?0:1;
        
        for(int i=2; i<=n; i++){
            int single = s[i-1] - '0';
            int two = stoi(s.substr(i-2, 2));
            if (single >= 1 && single <= 9) dp[i] += dp[i-1];
            if (two >= 10 && two <= 26) dp[i] += dp[i-2];
        }
        return dp[n];
        
    }
};
/*
s  =  1892
dp = 11222
*/
