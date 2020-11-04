class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        if (n < 2){
            for(int i=0; i<n; i++){
                res.push_back(i);
            }
            return res;
        }
        
        vector<unordered_set<int>> neighbors(n);
        
        for(auto x : edges){
            int start = x[0], end = x[1];
            neighbors[start].insert(end);
            neighbors[end].insert(start);
        }
        
        vector<int> leaves;
        for(int i=0; i<n; i++){
            if (neighbors[i].size() == 1) leaves.push_back(i); // is leaf, only 1 connection 
        }
        
        int remainingNodes = n;
        while(remainingNodes > 2){
            remainingNodes -= leaves.size();
            vector<int> newLeaves;
            
            for(int leaf : leaves){
                for(int neighbor : neighbors[leaf]){
                    neighbors[neighbor].erase(leaf);
                    if (neighbors[neighbor].size() == 1){
                        newLeaves.push_back(neighbor);
                    }
                }
            }
            
            leaves = newLeaves;
        }
        return leaves;
    }
};
