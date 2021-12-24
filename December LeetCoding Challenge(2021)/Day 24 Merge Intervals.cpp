class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1; i<n; i++){
            int start = intervals[i][0], end = intervals[i][1];
            while(!res.empty() && start <= res.back()[1]){
                auto temp = res.back(); res.pop_back();
                start = min(start, temp[0]);
                end = max(end, temp[1]);
            }
            res.push_back({start, end});
        }
        return res;
    }
};
