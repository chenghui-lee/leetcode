class Solution {
public:
    bool cycle(vector<vector<int>> &adj, vector<int> &status, int curr){
        if (status[curr] == 1) return true; // cycle detected
        else if (status[curr] == 2) return false;
        
        status[curr] = 1;
        for(int i=0; i<adj[curr].size(); i++){
            if (cycle(adj, status, adj[curr][i])){
                return true;
            }
        }
        status[curr] = 2;
        return false;
    }
    
    bool hasCycle(vector<vector<int>> &adj, int n){
        vector<int> status(n, 0); // 0 default, 1 visiting, 2 done processed
        for(int i=0; i<n; i++){
            if (status[i] == 0){
                if (cycle(adj, status, i)){
                    return true;
                }
            }
        }
        return false;
    }
    
    void dfs(vector<vector<int>> &adj, int num, vector<bool> &visited, stack<int> &temp){
        visited[num] = true;
        for(int i=0; i<adj[num].size(); i++){
            if (visited[adj[num][i]] == false){
                dfs(adj, adj[num][i], visited, temp);
            }
        }
        temp.push(num); // when have no where to go, push into stack
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<vector<int>> adj(numCourses);
        vector<int> res;
        
        for (auto x : prerequisites){
            adj[x[1]].push_back(x[0]);
        }
        
        if (hasCycle(adj, numCourses)) return res;
        stack<int> temp;
        
        for(int i=0; i<numCourses; i++){
            if (visited[i] == false){
                dfs(adj, i, visited, temp);
            }
        }
        while(!temp.empty()){
            res.push_back(temp.top());
            temp.pop();
        }
        return res;
    }
};
