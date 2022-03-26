class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return true;
        
        int toogle = 0; 
        /*
        0 -> default
        1 -> inc
        2 -> dec
        */
        for(int i=1; i<n; i++){
            if (nums[i] == nums[i-1]) continue;
            if (nums[i] > nums[i-1]){
                if (toogle < 0) return false;
                toogle = 1;
            }else{
                if (toogle > 0) return false;
                toogle = -1;
            }
        }
        return true;
        
    }
};
