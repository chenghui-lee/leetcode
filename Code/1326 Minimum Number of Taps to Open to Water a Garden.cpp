class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> jumps(ranges.size(), 0);
        
        for(int i=0; i<ranges.size(); i++){
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            jumps[left] = max(jumps[left], right - left);
        }
        
        int curEnd = 0, curFurthest = 0, count = 0;
        
        for(int i=0; i<jumps.size()-1; i++){ // jump game II
            if (i > curFurthest) return -1;
            curFurthest = max(curFurthest, i + jumps[i]);
            if (i == curEnd){
                curEnd = curFurthest;
                count++;
            }
        }
        return curFurthest >= n ? count : -1;
    }
};
