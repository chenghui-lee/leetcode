// https://www.youtube.com/watch?v=65j9zS-YWZo
class Solution {
public:
    int ways(char c1){
        if (c1 == '*') return 9;
        if (c1 == '0') return 0;
        return 1;
    }
    int ways(char c1, char c2){
        if (c1 == '*' && c2 == '*') return 15;
        
        if (c1 == '*'){
            if (c2 >= '0' && c2 <= '6') return 2; // 1x or 2x, given x less than eq to 6
            else return 1; // 1x
        }else if (c2 == '*'){
            if (c1 == '1') return 9; // 1*
            else if (c1 == '2') return 6; // 2*
            else return 0;
        }else{
            int num = (c1 - '0') * 10 + (c2 - '0');
            return num >= 10 && num <= 26;
        }
    }
    int numDecodings(string s) {
        int MOD = 1e9 + 7;
        vector<long> dp(2);
        dp[0] = 1, dp[1] = ways(s[0]);
        
        for(int i=1; i<s.size(); i++){
            long temp = ways(s[i]) * dp[1] + ways(s[i-1], s[i]) * dp[0];
            temp %= MOD;
            dp[0] = dp[1];
            dp[1] = temp;
        }
        
        return dp[1];
    }
};
