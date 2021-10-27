class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() < 2) return;
        int low = 0, high = nums.size()-1;
        
        for(int i=low; i<=high;){
            if (nums[i] == 0){
                swap(nums[i++], nums[low++]);
            }else if (nums[i] == 2){
                swap(nums[i], nums[high--]);
            }else{
                i++;
            }
        }
        
    }
};
