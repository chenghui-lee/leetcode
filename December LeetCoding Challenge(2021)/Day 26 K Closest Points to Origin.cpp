class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<long>, vector<vector<long>>, greater<vector<long>>> pq;
        
        for(int i=0; i<points.size(); i++){
            long dist = (long)points[i][0] * points[i][0] + (long)points[i][1] * points[i][1];
            pq.push({dist, i});
        }
        
        vector<vector<int>> res;
        for(int i=0; i<k; i++){
            auto cur = pq.top(); pq.pop();
            res.push_back(points[cur[1]]);
        }
        return res;
    }
};
