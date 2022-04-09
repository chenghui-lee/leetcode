class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m; // num, count
        for(int x : nums) m[x]++;
        
        priority_queue<pair<int, int>> pq;
        for(auto p : m) pq.push({p.second, p.first});
        
        vector<int> res;
        while(k--){
            auto cur = pq.top();
            pq.pop();
            res.push_back(cur.second);
        }
        return res;
    }
};
