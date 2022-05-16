class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        
        int moves[8][2] = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1,-1},{1,-1},{-1,1}};
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto [x, y] = q.front(); q.pop();
                if (x == n-1 && y == n-1) return steps + 1;
                
                for(auto m : moves){
                    int new_x = x + m[0], new_y = y + m[1];
                    if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n || grid[new_x][new_y] > 0) continue;
                    q.push({new_x, new_y});
                    grid[new_x][new_y] = 2;
                }
            }
            steps++;
        }
        return -1;
    }
};
