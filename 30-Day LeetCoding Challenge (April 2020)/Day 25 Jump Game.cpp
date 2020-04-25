class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastGood = nums.size()-1;
        for (int i = nums.size()-1; i>=0; i--){
          if (i+nums[i] >= lastGood){
            lastGood = i;
          }
        }
        return lastGood == 0;
    }
};

// another solution
bool canJump(vector<int>& nums) {
        int dis = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(i > dis) return false;
            dis = max(dis, i + nums[i]);
            if(dis >= nums.size() - 1) return true;
        }
        return false;
    }
