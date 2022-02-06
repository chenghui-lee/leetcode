class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // can be used for k, just substitude 2 with k
        int idx = 0;
        for(int x : nums){
            if (idx < 2 || nums[idx-2] < x){
                nums[idx++] = x;  
            }
        }
        return idx;
    }
};
