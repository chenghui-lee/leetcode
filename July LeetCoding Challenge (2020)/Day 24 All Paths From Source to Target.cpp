class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> row;
        row.push_back(0);
        dfs(graph, row, 0);
        return ans;
    }
    void dfs(vector<vector<int>>& graph, vector<int>& row, int curr){
        if(curr == graph.size() - 1){
            ans.push_back(row);
            return;
        }
        for(auto x : graph[curr]){
            row.push_back(x);
            dfs(graph, row, x);
            row.pop_back();
        }
    }
};
