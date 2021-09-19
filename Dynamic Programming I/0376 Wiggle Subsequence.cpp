class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n<2) return n;
        
        int idx = 1;
        while (idx < n && nums[idx-1] == nums[idx]){
            idx++;
        }
        if (idx == n) return 1; // all the same numbers
        
        bool increasing = nums[idx] > nums[0]; // what we expecting now
        int prev = nums[0], res = 1;
        for(int i=idx; i<n; i++){
            if ((increasing && nums[i] > prev) || (!increasing && nums[i] < prev)){
                increasing = !increasing;
                res++;
            }
            prev = nums[i];
        }
        return res;
    }
};
