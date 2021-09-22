class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0); // dp[i] = max product at i
        dp[1] = 1;
        
        for(int i=2; i<=n; i++){
            for(int j=1; j<= i/2; j++){
              // let's say i = 8, we are trying to fill dp[8]:if 8 can only be broken into 2 parts, the answer could be among 1 * 7, 2 * 6, 3 * 5, 4 * 4... 
              // but these numbers can be further broken. so we have to compare 1 with dp[1], 7 with dp[7], 2 with dp[2], 6 with dp[6]...etc
                dp[i] = max(dp[i], max(j, dp[j]) * max(i - j, dp[i-j]));
            }
        }
        return dp[n];
    }
};

// another solution using maths, o(n)
// https://leetcode.com/problems/integer-break/discuss/80689/A-simple-explanation-of-the-math-part-and-a-O(n)-solution
class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        int product = 1;
        
        while(n>4){
            product*=3;
            n-=3;
        }
        product*=n;
        
        return product;
    }
};
