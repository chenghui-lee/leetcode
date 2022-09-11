// old solution, follows lee125
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++){
            v.push_back({efficiency[i], speed[i]});
        }
        sort(v.begin(), v.end(), [](const pair<int, int> a, const pair<int, int> b) {
            return a.first==b.first?a.second>b.second:a.first>b.first;
            });
        
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

// do note that in line 32 in solution 1, the intermediate result might not be accurate
// because the newly added guy can be the one got removed from the team
// however it doesn't affect the final outcome as (sumSpeed*e) will always be lower
// then the current best result.


// solution 2, almost the same idea, just that we remove the engineer with the lowest
// speed before adding the new guy in. In this way the result is guarantee to be the 
// best in every situation.

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++){
            v.push_back({efficiency[i], speed[i]});
        }
        sort(rbegin(v), rend(v));
        long long  res = 0, sumSpeed = 0;
        priority_queue<int, vector<int>, greater<int>> pq; // min heap, to store speed
        
        for(auto& x : v){
            auto [e, s] = x; // efficiency, speed
            if (pq.size() == k){ // kick the engineer with the lowest speed first, before adding the new engineer
                sumSpeed -= pq.top();
                pq.pop();
            }
            sumSpeed += s;
            pq.push(s);
            res = max(res, sumSpeed * e);
        }        
        return res % (int)(1e9+7) ;
    }
};
