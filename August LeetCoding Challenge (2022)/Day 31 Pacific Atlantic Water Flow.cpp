class Solution {
/*
Instead of inside to outside, 
do outside to inside

*/
    public:
    vector<vector<int>> moves = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    
    void bfs(queue<pair<int, int>>& q, vector<vector<int>>& matrix, vector<vector<bool>>& visited){
        int m = matrix.size(), n = matrix[0].size();
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            for(int i=0; i<moves.size(); i++){
                int newX = x + moves[i][0];
                int newY = y + moves[i][1];
                
                if (newX < 0 || newX >=m || newY < 0 || newY >= n || visited[newX][newY] || matrix[x][y] > matrix[newX][newY]){
                    continue;
                }
                q.push({newX, newY});
                visited[newX][newY] = 1;
            }
        }
    }
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        if (matrix.size() == 0 || matrix[0].size() ==0) return res;
        int m = matrix.size(), n = matrix[0].size();

        
        vector<vector<bool>> atlanticVisited(m, vector<bool>(n)), pacificVisited(m, vector<bool>(n));
        queue<pair<int, int>> aq, pq; // atlanctic queue, pacific queue
        
        for(int i=0; i<m; i++){
            pacificVisited[i][0] = 1;
            pq.push({i, 0});
            atlanticVisited[i][n-1] = 1;
            aq.push({i, n-1});
        }
        
        for(int i=0; i<n; i++){
            pacificVisited[0][i] = 1;
            pq.push({0, i});
            atlanticVisited[m-1][i] = 1;
            aq.push({m-1, i});
        }
        bfs(aq, matrix, atlanticVisited);
        bfs(pq, matrix, pacificVisited);
        
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (atlanticVisited[i][j] && pacificVisited[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
