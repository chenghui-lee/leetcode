class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0;
        for(int i=0; i<nums.size()-1; i++){
            if (maxJump < i) return false;
            maxJump = max(maxJump, i + nums[i]);
            if (maxJump >= nums.size() - 1) {
                return true;
            }
        }
        return maxJump >= nums.size() -1;
    }
};
