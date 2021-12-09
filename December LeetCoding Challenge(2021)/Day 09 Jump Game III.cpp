class Solution {
public:
    bool res = false;
    void dfs(vector<int>& arr, int idx, vector<bool>& visited){
        if (idx < 0 || idx >= arr.size() || visited[idx]){
            return;
        }else if (arr[idx] == 0){
            res = true;
            return;
        }
        visited[idx] = 1;
        dfs(arr, idx+arr[idx], visited);
        dfs(arr, idx-arr[idx], visited);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        dfs(arr, start, visited);
        return res;
    }
};
