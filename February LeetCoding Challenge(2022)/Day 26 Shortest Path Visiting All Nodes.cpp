/*
In order to use unordered_set with pair, 
need to have some sort of hash function.

The hash function can be any, as long as avoiding collision.

Hence prime number is a better choice

The idea for this prob is to use BFS to go through all the levels, and we can check for duplicated path
using the visited bitmask.
Since n <= 12, so no prob.

1001 = node 0 and 3 visited

During the process, use OR operation to include the next node into the mask.

Return when all bits are set.

*/
class Solution {
private:
struct pair_hash {
    inline size_t operator()(const std::pair<int,int> & v) const {
        return v.first * 31 + v.second; // hash function, better if prime
    }
};
    
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        
        queue<pair<int, int>> q; // idx, visited mask
        unordered_set<pair<int, int>, pair_hash> visited; // idx, visited mask
        
        for(int i=0; i<n; i++){
            visited.insert({i, 1<<i}); // mark id, cur location as visited in mask
            q.push({i, 1<<i});
        }
        int res = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto cur = q.front(); q.pop();
                if (cur.second == ((1 << n) - 1)){ // visited all node, 1111 for n = 4
                    return res;
                }
                for(int nx : graph[cur.first]){
                    if (visited.find({nx, (1 << nx | cur.second)}) != visited.end()){ // if visited the same path (the same id and the same visited nodes)
                        continue;
                    }
                    q.push({nx, (1 << nx | cur.second)}); 
                    visited.insert({nx, (1 << nx | cur.second)}); // mark the current path(id, and all visited nodes)
                }
            }
            res++;
        }
        
        return -1;
        
        
    }
};
