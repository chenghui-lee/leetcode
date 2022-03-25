class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int res = 0;
        sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b){
            return a[1]-a[0] > b[1]-b[0];
        });
        // sort according to gap, higher gap btwn b-a will go to town A
        for(int i=0; i<n/2; i++){
            res += costs[i][0];
        }
        for(int i=n/2; i<n; i++){
            res += costs[i][1];
        }
        return res;
    }
};
