class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int x : nums){
            m[x]++;
        }
        
        int res = 0;
        for(auto p : m){
            int x = p.first;
            if (k > 0 && m.find(x +  k) != m.end() || k==0 && p.second > 1){
                res++;
            }
        }
        return res;
    }
};
