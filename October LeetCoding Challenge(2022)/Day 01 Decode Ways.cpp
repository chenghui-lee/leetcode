class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1; // 1 way to form, which is nothing
        dp[1] = s[0] == '0' ? 0 : 1;

        for(int i=2; i<=n; i++){
            int singleDigit = s[i-1] - '0';
            int doubleDigit = stoi(s.substr(i-2, 2));
            if (singleDigit >= 1 && singleDigit <= 9) dp[i] += dp[i-1];
            if (doubleDigit >= 10 && doubleDigit <= 26) dp[i] += dp[i-2];
        }
        return dp[n];
    }
};
/*
s  =  1892
dp = 11222
*/
