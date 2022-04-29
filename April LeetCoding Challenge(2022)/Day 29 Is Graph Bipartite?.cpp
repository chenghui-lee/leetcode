class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph, vector<int>& group, int cur, int grp){
        group[cur] = grp;
        for(int i=0; i<graph[cur].size(); i++){
            if (group[graph[cur][i]] == grp) return false;
            if (group[graph[cur][i]] == 0 && !dfs(graph, group, graph[cur][i], -grp)){
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> group(n, 0);
        for(int i=0; i<n; i++){
            if (group[i] == 0 && !dfs(graph, group, i, 1)){
                return false;
            }
        }
        return true;
    }
};
