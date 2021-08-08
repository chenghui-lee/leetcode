class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        for(int i=1; i<n; i++){
            stones[i] += stones[i-1];
        }
        // dp[i] = max score diff current player can achieve by taking first i stones
        // dp[i] = sum(stone[0:i]) - max(dp[i+1], dp[i+2], ... dp[n])
        // ans = max(dp(1), dp(2), ..., dp[n])
        int best = stones.back(); // take all
        for(int i=n-2; i>0; i--){
            best = max(best, stones[i] - best);
        }
        return best;
    }
};
