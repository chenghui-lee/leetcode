class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), idx = 1;
        for(int i=1; i<n; i++){
            if (nums[i] != nums[i-1]){
                nums[idx++] = nums[i];
            }
        }
        return min(idx, n);
    }
};
