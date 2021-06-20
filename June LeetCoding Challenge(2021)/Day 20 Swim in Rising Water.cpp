// dijkstra
class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited){
        if (i < 0 || i >= grid.size() || j < 0 || j>=grid.size() || visited[i][j]){
            return false;
        }
        return true;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        // level, x, y, min heap
        
        int res = 0;
        vector<vector<bool>> visited(n, vector<bool>(n));
        vector<vector<int>> moves = {{0,1},{1,0},{0,-1},{-1,0}};
        pq.emplace(grid[0][0], 0, 0);
        
        while(!pq.empty()){
            auto [level, i, j] = pq.top(); pq.pop();
            res = max(res, level);
            if (i == n-1 && j == n-1) return res;
            visited[i][j] = 1;
            
            for(auto m : moves){
                int x = m[0] + i, y = m[1] + j;
                if (isValid(grid, x, y, visited)) pq.emplace(grid[x][y], x,y);
            }
        }
        return res;
        
    }
};
