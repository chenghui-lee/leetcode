class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        
        k %= (m*n);
        
        vector<vector<int>> res(m, vector<int>(n));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int index = i*n + j;
                int newIndex = (index + k) % (m*n);
                
                int nr = newIndex / n;
                int nc = newIndex % n;
                
                res[nr][nc] = grid[i][j];
            }
        }
   
        return res;
    }
};
