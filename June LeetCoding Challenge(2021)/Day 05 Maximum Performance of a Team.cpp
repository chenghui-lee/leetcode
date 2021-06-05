class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++){
            v.push_back({efficiency[i], speed[i]});
        }
        sort(v.begin(), v.end(), [](const pair<int, int> a, const pair<int, int> b) { // sort efficient descending
            return a.first==b.first?a.second>b.second:a.first>b.first;
            });
        // sort(rbegin(v), rend(v))  <---- this also works
        long long  res = 0, sumSpeed = 0;
        priority_queue<int, vector<int>, greater<int>> pq; // min heap, to store speed
        
        /*
        
        since we sort the engineer in decreasing efficiency, we always assume the 
        current engineer is the one having lowest effiency.
        if current size > k, we simply remove the one with lowest speed.
        
        */
        for(auto& x : v){
            auto [e, s] = x; // efficiency, speed
            pq.emplace(s);
            sumSpeed += s;
            
            if (pq.size() > k){
                sumSpeed -= pq.top();
                pq.pop();
            }
            res = max(res, sumSpeed * e);
        }        
        return res % (int)(1e9+7) ;
    }
};
