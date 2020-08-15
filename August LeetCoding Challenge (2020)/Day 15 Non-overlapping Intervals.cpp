class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];        
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int del = 0;
        if(intervals.size() == 0) return del;
        sort(intervals.begin(), intervals.end(), comp);
        
        for(int i=0; i<intervals.size();){
            int end = intervals[i][1];
            int j = i+1;
            
            while(j<intervals.size() && intervals[j][0] < end) j++;
            del += (j - i) - 1;
            i = j;
        }
        return del;
    }
};
