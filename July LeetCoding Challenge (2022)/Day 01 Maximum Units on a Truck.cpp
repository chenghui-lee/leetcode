class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] > b[1]; // desc in the unit
        });
        int res = 0;
        for(int i=0; i<boxTypes.size() && truckSize > 0; i++){
            res += min(truckSize, boxTypes[i][0]) * boxTypes[i][1];   
            truckSize -= min(truckSize, boxTypes[i][0]);
        }
        return res;
    }
};
