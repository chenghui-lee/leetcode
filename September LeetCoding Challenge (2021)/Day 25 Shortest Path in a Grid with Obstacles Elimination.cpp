// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/discuss/451787/Python-O(m*n*k)-BFS-Solution-with-Explanation
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int step  = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};;
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX)); // min obstacles eliminated to reach i,j from 0,0
        queue<vector<int>> q; // [x,y, obs to reach here]
        q.push({0,0,0});
        dp[0][0] = 0;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto cur = q.front(); q.pop();
                if (cur[0] == m-1 && cur[1] == n-1) return step;
                
                for(auto mv : moves){
                    int x = cur[0] + mv[0], y = cur[1] + mv[1];
                    if (x < 0 || x >= m || y < 0 || y >= n) continue;
                    int obstacles = cur[2] + grid[x][y]; // how much obs to reach next lvl
                    // if we need more obstacles to reach the next level or already exceed k, we skip
                    if (obstacles >= dp[x][y] || obstacles > k) continue;
                    dp[x][y] = obstacles;
                    q.push({x,y,obstacles});
                }
            }
            step++;
        }
        return -1;
        
    }
};
