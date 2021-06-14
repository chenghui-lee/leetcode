class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(begin(boxTypes), end(boxTypes), [](const vector<int> a, const vector<int> b){
            return a[1] > b[1];
        });
        
        int res = 0;
        int i=0, n=boxTypes.size();
        while(truckSize > 0 && i<n){
            res += min(truckSize, boxTypes[i][0]) * boxTypes[i][1];   
            truckSize -= min(truckSize, boxTypes[i++][0]);
        }
        
        return res;
    }
};
