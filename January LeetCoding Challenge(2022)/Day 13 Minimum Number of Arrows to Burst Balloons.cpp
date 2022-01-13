class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), comp);
        int right = points[0][1];
        int res = 1;
        for(int i=0; i<points.size(); i++){
            if (points[i][0] > right){
                right = points[i][1];
                res++;
            }
        }
        return res;
    }
};
