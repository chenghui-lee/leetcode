class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j){
        if (dp[i][j]) return dp[i][j];
        
        vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int res = 1;
        for(auto d:dir){
            int x = i + d[0], y = j + d[1];
            if (x >=0 && x < matrix.size() && y>=0 && y<matrix[0].size() && matrix[i][j] < matrix[x][y]){
                res = max(res, 1 + dfs(matrix, dp, x, y));
            }
        }
        dp[i][j] = res;
        return res;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),  vector<int>(matrix[0].size()));
        if (!matrix.size()) return 0;
        
        int res = 0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                res = max(res, dfs(matrix, dp, i, j));
            }
        }
        return res;
    }
};
