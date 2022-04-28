// Dijkstra 
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int moves[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e6+1)); // min cost to reach i,j
        
        priority_queue<vector<int>> pq;
        pq.push({0,0,0});
        
        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            int d = -cur[0], r = cur[1], c = cur[2];
            if (d > dist[r][c]) continue; // already process
            if (r == m-1 && c == n-1) return d;
            for(int i=0; i<4; i++){
                int nr = r + moves[i][0], nc = c + moves[i][1];
                if (nr >=0 && nr < m && nc >=0 && nc < n){
                    int newDist = max(d, abs(heights[r][c] - heights[nr][nc]));
                    if (newDist < dist[nr][nc]){
                        dist[nr][nc] = newDist;
                        pq.push({-newDist, nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};
