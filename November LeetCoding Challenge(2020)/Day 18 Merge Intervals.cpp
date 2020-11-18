class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int start = intervals[0][0];
        int end = intervals[0][1];
        int n = intervals.size();
        
        if (n == 1){
            res.push_back({start, end});
            return res;
        }
        
        for(int i=1; i<n; i++){
            if (intervals[i][0] <= end){
                end = max(end, intervals[i][1]);
            }else{
                res.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            if (i == n-1) res.push_back({start, end});
        }
   
        return res;
    }
};
