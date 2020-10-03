class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int res = 0;
        for(int x : nums){
            m[x]++;
        }
        for(auto p : m){
            int x = p.first;
            if (k > 0 && m.find(x+k) != m.end() || k==0 && m[x] > 1){
                res++;
            }
        }
        return res;
    }
};
