class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> s;
        int mod, sum = 0, pre = 0;
        
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            mod = (k == 0 ? sum : sum % k);
            if (s.find(mod) != s.end()) return true;
            s.insert(pre);
            pre = mod;
        }
        return false;
    }
};
