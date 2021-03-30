class Solution {
private:
    static bool comp(vector<int>& a, vector<int>& b){
        if (a[0] == b[0]) return b[1] < a[1]; // desc in height
        else return a[0] < b[0]; // asc in width
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.size() == 0) return 0;
        sort(envelopes.begin(), envelopes.end(), comp);
        
        vector<int> dp;
        for(auto pair : envelopes){
            auto it = lower_bound(dp.begin(), dp.end(), pair[1]);
            if (it == dp.end()) dp.push_back(pair[1]);
            else *it = pair[1];
        }
        return dp.size();
    }
};
