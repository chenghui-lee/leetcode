// https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/discuss/156739/C%2B%2BJavaPython-Dijkstra-%2B-Priority-Queue
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        unordered_map<int, unordered_map<int, int>> graph; // from, to, dist
        for(auto e : edges){
            graph[e[0]][e[1]] = graph[e[1]][e[0]] = e[2];
        }
        
        priority_queue<pair<int, int>> pq; // move left, node
        unordered_map<int, int> seen; // seen[i] = reached node i, with seen[i] move left
        
        pq.push({maxMoves, 0});
        
        while(!pq.empty()){
            auto [moveLeft, i] = pq.top(); pq.pop();
            if (seen.count(i)) continue;
            seen[i] = moveLeft;
            for(auto next : graph[i]){
                int moves = moveLeft - next.second - 1;
                if (moves >= 0 && !seen.count(next.first)){
                    pq.push({moves, next.first});
                }
            }
        }
        int res = seen.size();
        for(auto e : edges){
            res += min(seen[e[0]] + seen[e[1]], e[2]);
        }
        return res;
    }
};
