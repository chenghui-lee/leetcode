class Solution {
public:
    vector<vector<int>> moves = {{1,0},{-1,0},{0,1},{0,-1}};
    
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j] || grid[i][j] == 0) return 0;

        visited[i][j] = 1;
        int area = 1;
        for(auto x: moves){
            area += dfs(grid, i + x[0], j + x[1], visited);
        }
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));

        int res = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (grid[i][j] && !visited[i][j]) res = max(res, dfs(grid, i, j, visited));
            }
        }
        return res;
    }
};
