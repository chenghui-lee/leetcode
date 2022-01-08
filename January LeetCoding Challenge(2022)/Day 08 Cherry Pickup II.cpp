class Solution {
public:
    int dp[70][70][70]; // dp[r][c1][c2] = max cherry from current r, robot1 at c1, robot2 at c2, to the bottom
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int m = grid.size(), n = grid[0].size();
        return dfs(grid, m, n, 0, 0, n-1);
    }
    
    int dfs(vector<vector<int>>& grid, int m, int n, int r, int c1, int c2){
        if (r == m) return 0;
        if (dp[r][c1][c2] >= 0) return dp[r][c1][c2];
        
        int res = 0;
        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                int nc1 = i+c1, nc2 = j+c2;
                if (nc1 >=0 && nc1 < n && nc2 >=0 && nc2 < n){
                    res = max(res, dfs(grid, m, n, r+1, nc1, nc2));
                }
            }
        }
        int cherry = (c1 == c2) ? grid[r][c1] :  grid[r][c1] + grid[r][c2]; // if same box, only take one
        return dp[r][c1][c2] = res + cherry;
    }
};
