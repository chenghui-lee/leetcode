class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto x : nums) m[x]++;
        
        int res = 0;
        for(auto [x, count] : m){
            if (k-x == x) res += count / 2;
            else if (m.count(k-x)){
                int temp = min(count, m[k-x]);
                res += temp;
                m[x] -= temp;
                m[k-x] -= temp;
            }
        }
        return res;
    }
};
