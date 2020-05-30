class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        if (K==points.size()) return points;
        vector<pair<double,int>> distance;
        for (int i=0; i<points.size();i++){
            int x = points[i][0], y = points[i][1];
            double dist = sqrt(pow(x,2)+pow(y,2));
            distance.push_back(make_pair(dist, i));
        }
        sort(distance.begin(),distance.end());
        vector<vector<int>> ans;
        for (int i =0; i<K;i++){
            ans.push_back(points[distance[i].second]);
        }
        return ans;
    }
};
