// https://www.youtube.com/watch?v=OF5bgClonGM
class Solution {
public:
    int find(vector<int>& par, int x){
        if (x != par[x]){
            par[x] = find(par, par[x]);
        }
        return par[x];
    }
    void union_ (vector<int>& par, int x, int y){
        int r1 = find(par, x), r2 = find(par, y);
        if (r1 != r2) par[r1] = r2;
    }
    
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        map<int, vector<pair<int, int>>> val2Pos; // val, position
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                val2Pos[matrix[i][j]].push_back({i, j});
            }
        }
        
        vector<int> rowMaxRank(m);
        vector<int> colMaxRank(n);
        vector<vector<int>> res(m, vector<int>(n));
        
        for(auto& p : val2Pos){
            vector<int> parents(m+n);
            iota(parents.begin(), parents.end(), 0);
            
            // group numbers on the same col and row
            for(auto& [i, j] : p.second){
                union_(parents, i, j+n);
            }
            
            unordered_map<int, int> root2Rank;
            
            for(auto& [i, j] : p.second){
                int root = find(parents, i); // find(j) also can, same root since we merged
                root2Rank[root] = max(root2Rank[root], max(rowMaxRank[i], colMaxRank[j]) + 1);
            }
            
            // update result
            for(auto& [i, j] : p.second){
                int root = find(parents, i);
                int rank = root2Rank[root];
                res[i][j] = rank;
                rowMaxRank[i] = rank;
                colMaxRank[j] = rank;
            }
        }
        
        return res;
    }
};
