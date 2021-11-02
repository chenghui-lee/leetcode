class Solution {
public:
    int m, n, res = 0, count = 1;
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startX, startY;
        m = grid.size(), n = grid[0].size();
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (grid[i][j] == 1){
                    startX = i, startY = j;
                }else if (grid[i][j] == 0) count++;
            }
        }
        dfs(startX, startY, grid);
        return res;
    }
    
    void dfs(int i, int j, vector<vector<int>>& grid){
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] < 0){
            return;
        }
        if (grid[i][j] == 2){
            if (count == 0) res++;
            return;
        }
        grid[i][j] = -2;
        count--;
        dfs(i+1, j, grid);
        dfs(i, j+1, grid);
        dfs(i-1, j, grid);
        dfs(i, j-1, grid);
        grid[i][j] = 0;
        count++;
    }
};
