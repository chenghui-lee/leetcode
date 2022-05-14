class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<int> shortestPath(n, INT_MAX);
        vector<vector<pair<int, int>>> graph(n); // <dest, cost>
        
        for(auto t : times){
            int u = t[0], v = t[1], w = t[2];
            graph[u-1].push_back({v-1, w});
        }
        
        shortestPath[k-1] = 0;
        queue<pair<int, int>> q;
        q.push({k-1, 0});
        
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            auto u = cur.first, time = cur.second;
            for(auto v : graph[u]){
                int nextTime = time + v.second;
                if (nextTime < shortestPath[v.first]){
                    q.push({v.first, nextTime});
                    shortestPath[v.first] = nextTime;
                }
            }
        }
        int res = 0;
        for(int x : shortestPath){
            if (x == INT_MAX) return -1;
            res = max(res, x);
        }
        return res;
    }
};
