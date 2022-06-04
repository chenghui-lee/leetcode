class Solution {
public:
    vector<vector<string>> res;
    
    bool valid(vector<string>& grid, int row, int col){
        // check col
        for(int i=0; i<=row; i++){
            if (grid[i][col] == 'Q') return false;
        }
        // left top diagonal
        for(int i=row, j=col; i>=0 && j>=0; i--, j--){
            if (grid[i][j] == 'Q') return false;
        }
        // top right diagonal
        for(int i=row, j=col; i>=0 && j<grid.size(); i--, j++){
            if (grid[i][j] == 'Q') return false;
        }
        return true;
    }
    
    void dfs(vector<string>& grid, int row){
        if (row == grid.size()){
            res.push_back(grid);
            return;
        }
        // loop through the col
        for(int i=0; i<grid[0].size(); i++){
            if (valid(grid, row, i)){
                grid[row][i] = 'Q';
                dfs(grid, row+1);
                grid[row][i] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n, string(n, '.'));
        dfs(grid, 0);
        return res;
    }
};
