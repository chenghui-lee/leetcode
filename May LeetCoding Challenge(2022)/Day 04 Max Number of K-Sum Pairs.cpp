class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> m; // num, count
        int res = 0;
        for(int x : nums){
            m[x]++;
            int target = k - x;
            if ((m[target] > 0 && target != x) || (target == x && m[target] >= 2)){
                res++;
                m[target]--;
                m[x]--;
            }
        }
        return res;
    }
};
