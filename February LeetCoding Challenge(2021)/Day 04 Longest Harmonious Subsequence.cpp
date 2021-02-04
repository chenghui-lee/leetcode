class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<long, int> m;
        for(auto& x : nums){
            m[x]++;
        }
        int res = 0;
        for(auto& x : nums){
            if (m[x+1]){
                res = max(res, m[x] + m[x+1]);
            }
        }
        return res;
    }
};
