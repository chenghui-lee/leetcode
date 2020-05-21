class Solution {
public:
int countSquares(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return 0;
        int result = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for (int i = 1; i<=m; i++){
        	for (int j = 1; j<=n; j++){
        		if (matrix[i-1][j-1] == 1){
        			dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
        			result += dp[i][j];
        		}
        	}
        }
        return result;
}
};
