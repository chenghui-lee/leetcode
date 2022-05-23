class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        // max subset with i zero and j one
        
        for(string s : strs){
            int one = 0, zero = 0;
            for(char ch : s){
                if (ch == '0') zero++;
                else one++;
            }
            // knapsack, from m to 0 to avoid recalculation
            for(int i=m; i>=zero; i--){
                for(int j=n; j>=one; j--){
                    dp[i][j] = max(dp[i][j], dp[i-zero][j-one] + 1);
                }
            }
            
        }
        return dp[m][n];
    }
};
