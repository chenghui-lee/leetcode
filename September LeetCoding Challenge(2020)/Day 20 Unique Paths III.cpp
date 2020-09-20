class Solution {
public:
    int res = 0, empty = 1; // empty for how many empty space we can move
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startX, startY;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 0) empty++;
                else if (grid[i][j] == 1){
                    startX = i;
                    startY = j;
                }
            }
        }
        dfs(grid, startX, startY);
        return res;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] < 0){
            return;
        }
        if(grid[i][j] == 2){
            if(empty == 0){
                res++;
            }
            return;
        }
        grid[i][j] = -2;
        empty--;
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
        grid[i][j] = 0;
        empty++;
    }
};
