class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> res(n, -1);
        for(int i=0; i<n; i++){
            int curRow = 0, curCol = i;
            while(curRow < m){
                // can go right if the cur and the next col having the same direction
                if (grid[curRow][curCol] == 1 && curCol + 1 < n && grid[curRow][curCol + 1] == 1) {
                    curRow++;
                    curCol++;
                } // can go left if the cur and the prev col having the same direction
                else if (grid[curRow][curCol] == -1 && curCol - 1 >= 0 && grid[curRow][curCol - 1] == -1) {
                curCol--; curRow++;
                } else{
                    break; // cant proceed
                }

            }
            // check if it manages to reach the last row
            res[i] = curRow == m ? curCol : -1;
        }
        return res;
    }
};
