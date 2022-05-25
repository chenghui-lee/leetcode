class Solution {
private:
    static bool comp(vector<int>& a, vector<int>& b){
        if (a[0] == b[0]) return a[1] > b[1]; // desc in height if width are the same
        return a[0] < b[0]; // otherwise acs in width
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> dp;
        // Longest increasing subsequence
        // LIS based on height
        // Since width is strictly increasing, [3,3] may fit into [3,4]
        // But sorting height in descending solve this prob
        for(auto e : envelopes){
            auto it = lower_bound(dp.begin(), dp.end(), e[1]);
            if (it == dp.end()) dp.push_back(e[1]);
            else *it = e[1];
        }
        
        return dp.size();
    }
};
