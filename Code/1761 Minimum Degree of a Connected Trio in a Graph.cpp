/*
Loop through every pair (2 vertices), 
check if any common linkage or not, then calculate the degree

*/

// adj matrix
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> adj(n+1, vector<bool>(n+1, false)); // storing small->big, in matrix form
        vector<int> degree(n+1, 0);
        
        for(auto e : edges){
            adj[min(e[0], e[1])][max(e[0], e[1])] = true; // insert small -> big
            degree[e[0]]++;
            degree[e[1]]++;
            
        }
        
        int res = INT_MAX;
        for(int i=1; i<=n; i++){
            // loop through all the next vertices
            for(int j=i+1; j<=n; j++){
                // loop through all the next vertices, see if 3 of them linked
                if (adj[i][j]){ // if first and second linked
                    for(int k=j+1; k<=n; k++){
                    if (adj[i][k] && adj[j][k]){ // if 1-3 and 2-3 
                        res = min(res, degree[i] + degree[j] + degree[k] - 6);
                        // -6 because of themself
                    }
                }
                }
                
            }
        }
        return res == INT_MAX ? -1 : res;
        
    }
};

// similar idea, but use adj list... slower in this question and result in TLE
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<set<int>> adj(n+1); // storing small->big, to avoid duplicate checking
        vector<int> degree(n+1, 0);
        
        for(auto e : edges){
            adj[min(e[0], e[1])].insert(max(e[0], e[1])); // insert small -> big
            degree[e[0]]++;
            degree[e[1]]++;
            
        }
        
        int res = INT_MAX;
        for(int i=1; i<=n; i++){
            // loop through all the linked vertices
            for(auto j=begin(adj[i]); j != end(adj[i]); ++j){
                // loop through all the third linked vertices, see if second linked with third
                for(auto k=next(j); k != end(adj[i]); ++k){
                    if (adj[*j].find(*k) != adj[*j].end()){ // if the second linked with third
                        res = min(res, degree[i] + degree[*j] + degree[*k] - 6);
                        // -6 because of themself
                    }
                }
            }
        }
        return res == INT_MAX ? -1 : res;
        
    }
};
