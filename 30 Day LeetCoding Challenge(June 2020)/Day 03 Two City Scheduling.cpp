class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){ // if true, wont swap, we sort by highest saving 
        return a[1]-a[0] > b[1]-b[0];
    }
        
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ans = 0;
        sort(costs.begin(), costs.end(), comp);
        // nth_element(costs.begin(), costs.size()/2, comp) use the middle as pivot, as we need only the cost, so perfect sort doesnt matter
        for (int i=0; i<costs.size()/2;i++){
            ans += costs[i][0];
        }
        for (int i=(costs.size()/2);i<costs.size(); i++){
            ans += costs[i][1];
        }
        return ans;
    }
};
