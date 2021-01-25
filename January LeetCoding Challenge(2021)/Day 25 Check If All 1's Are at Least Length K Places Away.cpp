class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lastOne = -1;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if (nums[i] == 1 && lastOne != -1 && i-lastOne-1 < k) return false;
            else if(nums[i] == 1) lastOne = i;
        }
        if (nums[0] == nums[n-1] && n < k) return false;
        return true;
    }
};
