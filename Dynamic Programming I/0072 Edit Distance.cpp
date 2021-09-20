/*
If word1[i - 1] != word2[j - 1], we need to consider three cases.

1. Replace word1[i - 1] by word2[j - 1] (dp[i][j] = dp[i - 1][j - 1] + 1);
2. If word1[0..i - 1) = word2[0..j) then delete word1[i - 1] (dp[i][j] = dp[i - 1][j] + 1);
3. If word1[0..i) + word2[j - 1] = word2[0..j) then insert word2[j - 1] to word1[0..i) (dp[i][j] = dp[i][j - 1] + 1).

*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i=1; i<=m; i++){
            dp[i][0] = i;
        }
        for(int i=1; i<=n; i++){
            dp[0][i] = i;
        }
        dp[0][0] = 0; // no change required when both are empty
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if (word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(min(dp[i-1][j-1],dp[i-1][j]), dp[i][j-1]) + 1;
                    // replace word1[i-1] with word2[j-1] or delete the current char at word1 or insert a new char 
                }
            }
        }
        return dp[m][n];
    }
};
