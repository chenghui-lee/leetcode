class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        set<pair<int, int>> fresh;
        queue<pair<int, int>> rotten;
        int m = grid.size(), n = grid[0].size();
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (grid[i][j] == 1){
                    fresh.insert({i, j});
                }else if (grid[i][j] == 2){
                    rotten.push({i, j});
                }
            }
        }
        
        vector<vector<int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int res = 0;
        
        while(!rotten.empty()){
            if (fresh.empty()){
                return res;
            }
            int sz = rotten.size();
            for(int i=0; i<sz; i++){
                auto cur = rotten.front(); rotten.pop();
                int x = cur.first, y = cur.second;
                for(auto& mv : moves){
                    int new_x = x + mv[0], new_y = y + mv[1];
                    // cout << new_x << " " << new_y << "\n";
                    if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && fresh.find({new_x, new_y}) != fresh.end()){
                        fresh.erase({new_x, new_y});
                        rotten.push({new_x, new_y});
                    }
                }
            }
            res++;
        }
        return fresh.empty() ? res : -1;
        
    }
};
