// https://www.youtube.com/watch?v=RYaakWv5m6o
// https://leetcode.com/problems/critical-connections-in-a-network/discuss/1174182/Critical-Connections-in-a-Network-or-Tarjan's-Algorithm-or-Explanation-and-Comments
class Solution {
public:
    vector<vector<int>> res;
    unordered_map<int, vector<int>> graph;
    
    void dfs(int prevNode, int curNode, int curRank, vector<bool>& visited, vector<int>& rank){
        rank[curNode] = curRank;
        visited[curNode] = 1;
        
        for(auto next : graph[curNode]){
            if (next == prevNode) continue;
            if (!visited[next]){
                dfs(curNode, next, curRank+1, visited, rank);
            }
            rank[curNode] = min(rank[curNode], rank[next]);
            if (rank[next] == curRank+1){
                res.push_back({curNode, next});
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for (auto x : connections){
            int a = x[0], b = x[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<int> rank(n);
        for(int i=0; i<n; i++){
            rank[i] = i;
        }
        vector<bool> visited(n);
        int prevNode = -1, curNode = 0, curRank = 0;
        dfs(prevNode, curNode, curRank, visited, rank);
        return res;
    }
};
