// Dijkstra's algorithm
// Bellman ford algorithm will also do well in this problem because the problem set is small
// https://www.youtube.com/watch?v=gsscC1cmL-Y
class Solution {
public:
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
       vector<vector<pair<int,int>>> graph(n); // v[i] = from i to [next, cost] 
       for(auto x : flights){
        graph[x[0]].push_back({x[1], x[2]});
       }
       priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
       pq.emplace(0, src, K+1); // accumulated cost, cur location, available stops

       while(!pq.empty()){
        auto [accumulatedCost, cur, stops] = pq.top(); pq.pop();
        if (cur == dst) return accumulatedCost;
        if (!stops) continue; // no more step available
        for (auto next : graph[cur]){
                auto [place, cost] = next;
                pq.emplace(accumulatedCost + cost, place, stops -1);
        }
        }
        return -1;
}
};
