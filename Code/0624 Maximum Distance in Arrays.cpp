class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int result = 0;
        int globalMin = arrays[0][0], globalMax = arrays[0].back();
        int curMin, curMax;

        int m = arrays.size();
        for(int i=1; i<m; i++) {
            int len = arrays[i].size();
            curMin = arrays[i][0];
            curMax = arrays[i][len-1];
            result = max(result, abs(curMax - globalMin));
            result = max(result, abs(globalMax - curMin));

            globalMin = min(globalMin, curMin);
            globalMax = max(globalMax, curMax);
        }
        return result;
    }
};
