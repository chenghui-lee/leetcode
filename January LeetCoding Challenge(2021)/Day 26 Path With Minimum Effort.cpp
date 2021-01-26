// Solution 1
// BFS + Binary Search
// Time : O(mn log(max(h) - min(h))
// Kinda guess the value that minimize the abs diff

class Solution {
public:
    int moves[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    
    bool bfs(int cost, vector<vector<int>>& heights){ // exists a path to end
        int m = heights.size(), n = heights[0].size();
        queue<pair<int,int>> q;
        vector<vector<bool>> visited (m, vector<bool>(n));
        
        q.push({0,0});
        visited[0][0] = 1;
        
        while(!q.empty()){
            auto [r, c] = q.front(); q.pop();
            if (r == m-1 && c == n-1) return true;
            for(int i=0; i<4; i++){
                int nr = r + moves[i][0], nc = c + moves[i][1];
                if (nr >=0 && nr < m && nc >=0 && nc < n && !visited[nr][nc] && abs(heights[r][c] - heights[nr][nc]) <= cost){
                    q.push({nr, nc});
                    visited[nr][nc] = 1;
                }
            }
        }
        return false;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int l = 0, r = 1e6;
        while(l<r){
            int m = l + (r-l)/2;
            if (bfs(m, heights)) r = m;
            else l = m+1;
        }
        return l;
    }
};

// Solution 2
// Dijikstra
// Time : O(mn logmn)
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int moves[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e6+1));
        
        priority_queue<vector<int>> pq;
        pq.push({0,0,0});
        
        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            int d = -cur[0], r = cur[1], c = cur[2];
            if (d > dist[r][c]) continue;
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
