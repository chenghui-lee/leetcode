class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = newInterval[0];
        int end = newInterval[1];
        
        // insert according to start
        auto it = intervals.begin();
        while(it != intervals.end() && (*it)[0] < start) it ++;
        intervals.insert(it, newInterval);
        
        // merge the intervals
        vector<vector<int>> res;
        for(auto x : intervals){
            if(res.empty() || x[0] > res.back()[1]){
                res.push_back(x);
            }else{
                res.back()[1] = max(res.back()[1], x[1]);
            }
        }
        return res;
    }
};
