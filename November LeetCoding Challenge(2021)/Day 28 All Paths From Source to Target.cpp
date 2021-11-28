class Solution {
public:
    vector<vector<int>> res;
    void dfs(int index, vector<vector<int>>& graph, vector<int>& cur){
        if (index == graph.size() -1){
            res.push_back(cur);
            return;
        }
        for(auto x : graph[index]){
            cur.push_back(x);
            dfs(x, graph, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> cur;
        cur.push_back(0);
        dfs(0, graph, cur);
        return res;
    }
};
