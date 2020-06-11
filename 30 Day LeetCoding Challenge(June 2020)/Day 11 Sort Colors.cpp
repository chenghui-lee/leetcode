// we want to put all the 0 at the left side of the array, 1 at middle and 2 at the back
// https://leetcode.com/problems/sort-colors/discuss/26474/Sharing-C%2B%2B-solution-with-Good-Explanation
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low =0, mid =0, high = nums.size()-1;
        while(mid<=high){
            if (nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
                
            }else if (nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
