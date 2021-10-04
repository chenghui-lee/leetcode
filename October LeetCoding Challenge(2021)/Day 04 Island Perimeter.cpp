class Solution {
public:
    int res = 0;
    void dfs(vector<vector<int>>& grid, int i, int j){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0){
            res++;
            return;
        }else if (grid[i][j] == 2) return;
        grid[i][j] = 2;
        dfs(grid, i+1, j);
        dfs(grid, i, j+1);
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
    }
    
    
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if (grid[i][j] == 1){
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};
