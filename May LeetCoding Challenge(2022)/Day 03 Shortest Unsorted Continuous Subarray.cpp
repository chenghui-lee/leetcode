class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = -1, right = n - 1;
        
        int mx = INT_MIN;
        for(int i=0; i<n; i++){
            mx = max(mx, nums[i]);
            if (nums[i] < mx) right = i; // if got number smaller than the prev max (at left)
        }
        int mn = INT_MAX;
        for(int i=n-1; i>=0; i--){
            mn = min(mn, nums[i]);
            if (nums[i] > mn) left = i; // if got number larger than prev min (at right side)
        }
        if (left == -1) return 0;
        else return right - left + 1;
    }
};
