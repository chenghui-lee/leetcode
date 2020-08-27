class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<pair<int,int>, int> dict;
        vector<int> result(intervals.size());
        for(int i=0; i<intervals.size(); i++){
            dict[{intervals[i][0], intervals[i][1]}] = i;
        }
        sort(intervals.begin(), intervals.end());
        for(int i=0; i<intervals.size(); i++){
            int end = intervals[i][1];
            int j = i+1;
            while(j<intervals.size() && intervals[j][0] < end) j++;
            int ans;
            if(j==intervals.size()) ans = -1;
            else ans = dict[{intervals[j][0], intervals[j][1]}];
            result[dict[{intervals[i][0], intervals[i][1]}]] = ans;
        }
        return result;
    }
};
