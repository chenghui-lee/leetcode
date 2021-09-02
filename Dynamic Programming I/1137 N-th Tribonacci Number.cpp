class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1;
        
        int a = 0, b = 1, c = 1, ans = 2;
        for(int i=3; i<=n; i++){
            ans = a+b+c;
            a = b, b = c, c = ans;
        }
        return ans;
    }
};

// more brilliant solution
class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp = {0, 1, 1};
        
        for(int i=3; i<=n; i++){
            dp[i % 3] =  dp[0] + dp[1] + dp[2];
        }
        return dp[n % 3];
    }
};
