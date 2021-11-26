class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        if (target > nums[high]) return high + 1;
        else if (target < nums[low]) return 0;
        
        while(low < high){
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};
