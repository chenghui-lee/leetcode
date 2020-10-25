class Solution {
public:
    bool winnerSquareGame(int n) {
        int sqr = sqrt(n);
        if (sqr*sqr == n) return true; // if n is a perfect square, then Alice will automatically win
        
        vector<bool> dp(n+1, false);
        for(int i=1; i<=n; i++){
            for(int j=1; j*j <=i; j++){
                if (!dp[i-j*j]){ // the next step have no move left, so Alice will win
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
