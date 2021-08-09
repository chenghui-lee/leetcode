class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), idx = 0;
        for(int i=0; i<n; i++){
            if (nums[i] != val){
                nums[idx++] = nums[i];
            }
        }
        return min(idx, n);
    }
};
