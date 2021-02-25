class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int low = -1, high = n-1;
        
        int mx = INT_MIN;
        for(int i=0; i<n; i++){
            mx = max(mx, nums[i]);
            if (nums[i] < mx) high = i;
        }
        int mn = INT_MAX;
        for(int i=n-1; i>=0; i--){
            mn = min(mn, nums[i]);
            if (nums[i] > mn) low = i;
        }
        if (low == -1) return 0;
        else return high - low + 1;
        
        
    }
};
