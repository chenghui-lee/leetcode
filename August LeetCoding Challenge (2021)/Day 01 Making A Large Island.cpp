// union find
class Solution {
private:
    struct UnionFind {
        vector<int> parent;

        UnionFind(int N){
            parent = vector<int> (N, -1);
        }
        int root(int x){
            if (parent[x] < 0) return x;
            return parent[x] = root(parent[x]);
        }
        bool unite(int x, int y){
            int parentA = root(x);
            int parentB = root(y);
            if (parentA == parentB) return false;
            if (parent[parentA] > parent[parentB]) swap(parentA, parentB);

            parent[parentA] += parent[parentB];
            parent[parentB] = parentA;
            return true;

        }
        int size(int x){
            return -parent[root(x)];
        }
    };
public:
    bool isValid(vector<vector<int>>& grid, int i, int j){
        return (i >= 0 && i < grid.size() && j >=0 && j < grid[0].size() && grid[i][j] == 1);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        UnionFind uf(row * col);
        vector<vector<int>> moves = {{0,1},{1,0},{-1,0},{0,-1}};
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if (grid[i][j] == 1){
                    int idx = i * col + j;
                    
                    for(auto m : moves){
                        int x = i + m[0], y = j + m[1];
                        int idx2 = x * col + y;
                        if (isValid(grid, x, y)){
                            uf.unite(idx, idx2);
                        }
                    }
                }
            }
        }
        int res = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if (grid[i][j] == 0){
                    int curSize = 1;
                    unordered_set<int> neighbor;
                    for(auto m : moves){
                        int x = i + m[0], y = j + m[1];
                        int nextIdx = x * col + y;
                        if (isValid(grid, x, y) && neighbor.find(uf.root(nextIdx)) == neighbor.end()){
                            curSize += uf.size(nextIdx);
                            neighbor.insert(uf.root(nextIdx));
                        }
                    }
                    res = max(res, curSize);   
                }
            }
        }
        return res == 0 ? row*col : res;
    }
};

// dfs @ lee215
    int N;
    int largestIsland(vector<vector<int>>& grid) {
        N = grid.size();
        //DFS every island and give it an index of island
        int index = 2, res = 0;
        unordered_map <int, int>area;
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < N; ++y) {
                if (grid[x][y] == 1) {
                    area[index] = dfs(grid, x, y, index);
                    res = max(res, area[index++]);
                }
            }
        }
        //traverse every 0 cell and count biggest island it can conntect
        for (int x = 0; x < N; ++x)
            for (int y = 0; y < N; ++y)
                if (grid[x][y] == 0) {
                    unordered_set<int> seen = {};
                    int cur = 1;
                    for (auto p : move(x, y)) {
                        index = grid[p.first][p.second];
                        if (index > 1 && seen.count(index) == 0) {
                            seen.insert(index);
                            cur += area[index];
                        }
                    }
                    res = max(res, cur);
                }
        return res;
    }

    vector<pair<int, int>> move(int x, int y) {
        vector<pair<int, int>> res;
        for (auto p : vector<vector<int>> {{1, 0}, { -1, 0}, {0, 1}, {0, -1}}) {
            if (valid(x + p[0], y + p[1]))
                res.push_back(make_pair(x + p[0], y + p[1]));
        }
        return res;
    }

    int valid(int x, int y) {
        return 0 <= x && x < N && 0 <= y && y < N;
    }

    int dfs(vector<vector<int>>& grid, int x, int y, int index) {
        int area = 0;
        grid[x][y] = index;
        for (auto p : move(x, y))
            if (grid[p.first][p.second] == 1)
                area += dfs(grid, p.first, p.second, index);
        return area + 1;
    }
