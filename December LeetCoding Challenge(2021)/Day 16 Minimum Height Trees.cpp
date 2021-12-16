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
        
        vector<unordered_set<int>> adj(n);
        for(auto edge : edges){
            int start = edge[0], end = edge[1];
            adj[start].insert(end);
            adj[end].insert(start);
        }
        vector<int> leaves;
        for(int i=0; i<n; i++){
            if (adj[i].size() == 1) leaves.push_back(i);
        }
        
        int remainingNodes = n;
        while(remainingNodes > 2){
            remainingNodes -= leaves.size();
            vector<int> newLeaves;
            for(int leaf : leaves){
                for(int link : adj[leaf]){
                    adj[link].erase(leaf);
                    if (adj[link].size() == 1) newLeaves.push_back(link);
                }
                
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};
