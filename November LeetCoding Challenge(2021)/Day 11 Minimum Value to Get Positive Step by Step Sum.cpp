class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int prefix = 0;
        int globalLowest = INT_MAX;
        for(auto x : nums){
            prefix += x;
            globalLowest = min(globalLowest, prefix);
        }
        if (globalLowest >= 1) return 1;
        else return 1 - globalLowest;
    }
};
