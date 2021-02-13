class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int endRow = n-1, endCol = m-1;
        int res = 0;
        
        queue<pair<int, int>> q;
        q.push({0,0});
        
        int moves[8][2] = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1,-1},{1,-1},{-1,1}};
        
        while(!q.empty()){
            res++;
            for(int i=q.size(); i>0; i--){
                auto cur = q.front();
                q.pop();
                int x = cur.first, y = cur.second;
                
                if (grid[x][y] == 1) continue;
                if(x == endRow && y == endCol) return res;
                
                grid[x][y] = 1;
                
                for(auto move : moves){
                    int newRow = x + move[0], newCol = y + move[1];
                    if (newRow >=0 && newCol >=0 && newRow < n && newCol < m && !grid[newRow][newCol]){
                        q.push({newRow,newCol});
                    }
                }
            }
        }
        
        
        return -1;
    }
};
