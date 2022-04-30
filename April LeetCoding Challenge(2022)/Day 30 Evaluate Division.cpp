class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph; // a -> b -> weight
        
        // form graph
        for(int i=0; i<equations.size(); i++){
            auto a = equations[i][0], b = equations[i][1];
            double val = values[i];
            graph[a][b] = val;
            graph[b][a] = 1 / val;
        }
        
        vector<double> res;
        for(int i=0; i<queries.size(); i++){
            auto a = queries[i][0], b = queries[i][1];
            if (!graph.count(a) || !graph.count(b)){
                res.push_back(-1.0);
                continue;
            }else{
                unordered_set<string> visited;
                double tmp = dfs(a, b, graph, visited);
                res.push_back(tmp);
            }
        }
        return res; 
    }
    
    double dfs(string a, string b, unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited){
        if (a == b) return 1.0;
        else if (graph[a].find(b) != graph[a].end()) return graph[a][b];
        visited.insert(a);
        
        for(auto neighbour : graph[a]){
            if (visited.find(neighbour.first) != visited.end()) continue;
            
            double dist = dfs(neighbour.first, b, graph, visited);
            if (dist > 0) return dist * neighbour.second;
        }
        return -1.0;
    }
};
