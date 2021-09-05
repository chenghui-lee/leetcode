class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = nums[0], n = nums.size();
        if (n == 1) return true;
        
        for(int i=0; i<n-1; i++){
            if (mx < i) return false;
            mx = max(mx, i + nums[i]);
            if (mx >= n-1) return true;
        }
        return false;
    }
};
