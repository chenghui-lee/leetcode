// https://leetcode.com/problems/stone-game/discuss/154610/DP-or-Just-return-true
// https://www.youtube.com/watch?v=WxpIHvsu1RI
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(n));
        // dp[i][j] = given piles i to j-th, the score for both player
        // first->alex, second->lee
        
        for(int i=0; i<n; i++){
            dp[i][i] = {piles[i], 0}; // player 1 take the only number, player 2 nothing left
        }
        
        for(int k=1; k<n; k++){
            for(int i=0; i+k<n; i++){
                int j = i+k;
                
                // cur = num[i] + best in second turn for the remaining nums
                int pickLeft = piles[i] + dp[i+1][j].second;
                int pickRight = piles[j] + dp[i][j-1].second;
                
                if (pickLeft > pickRight){
                    int leeScore = dp[i+1][j].first;
                    dp[i][j] = {pickLeft, leeScore};
                }else{
                    int leeScore = dp[i][j-1].first;
                    dp[i][j] = {pickRight, leeScore};
                }
            }
        }
        return dp[0][n-1].first > dp[0][n-1].second;
        
        
    }
};
