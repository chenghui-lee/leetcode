class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> bestStepsToReachHere(m, vector<int>(n, INT_MAX));

        queue<vector<int>> q;
        q.push({0, 0, 0}); // i,j,steps to reach here
        bestStepsToReachHere[0][0] = 0; // starting and ending will always be 0

        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto cur = q.front(); q.pop();
                if (cur[0] == m - 1 && cur[1] == n - 1) {
                    return steps;
                }
                for(auto dir : moves){
                    int x = cur[0] + dir[0];
                    int y = cur[1] + dir[1];
                    if (x < 0 || x >= m || y < 0 || y >= n) {
                        continue;
                    }
                    int stepsToReachNext = grid[x][y] + cur[2];
                    if (stepsToReachNext >= bestStepsToReachHere[x][y] || stepsToReachNext > k){
                        continue;
                    }
                    bestStepsToReachHere[x][y] = stepsToReachNext;
                    q.push({x,y,stepsToReachNext});
                }
            }
            steps++;
        }

        return -1;
    }
};
