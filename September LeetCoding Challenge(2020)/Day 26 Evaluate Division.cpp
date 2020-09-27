class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph; // a -> b -> ans
        int i=0;
        for(auto eq : equations){
            double k = values[i++];
            string a = eq[0], b = eq[1];
            graph[a][b] = k; //  a/b = k
            graph[b][a] = 1.0/k; //  b/a = 1/k
        }
        vector<double> ans;
        
        for(auto q: queries){
            string a = q[0], b = q[1];
            if (!graph.count(a) || !graph.count(b)){
                ans.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            double res = dfs(a, b, graph, visited);
            ans.push_back(res);
        }
        return ans;
    }
    
    double dfs(string a, string b, unordered_map<string, unordered_map<string, double>> graph, unordered_set<string>& visited){
        if (a==b) return 1.0;
        else if (graph[a].find(b) != graph[a].end()) return graph[a][b];
        visited.insert(a);
        
        for(auto next : graph[a]){
            string c = next.first;
            if(visited.count(c)) continue;
            double distance = dfs(c, b, graph, visited);
            if (distance > 0) return distance * graph[a][c]; // if path is valid
        }
        return -1.0;
    }
};
