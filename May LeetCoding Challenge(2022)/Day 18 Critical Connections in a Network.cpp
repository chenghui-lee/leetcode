class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& rank, int curNode, int curRank, int prevNode, vector<vector<int>>& res){
        rank[curNode] = curRank;
        visited[curNode] = 1;
        
        for(int next : graph[curNode]){
            if (next == prevNode) continue;
            if (!visited[next]){
                dfs(graph, visited, rank, next, curRank+1, curNode, res);
            }
            rank[curNode] = min(rank[curNode], rank[next]);
            if (rank[next] == curRank + 1){
                res.push_back({curNode, next});
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(auto c : connections){
            int u = c[0], v = c[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<bool> visited(n, false);
        vector<int> rank(n);
        iota(rank.begin(), rank.end(), 0);
        
        int curRank = 0, curNode = 0;
        vector<vector<int>> res;
        dfs(graph, visited, rank, curNode, curRank, curNode, res);
        return res;
    }
};
