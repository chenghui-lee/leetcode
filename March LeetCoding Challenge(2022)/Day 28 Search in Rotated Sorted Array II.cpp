class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        
        while(start <= end){
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] > nums[start]){ // left part sorted
                if (nums[start] > target || target > nums[mid]){
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }else if (nums[start] > nums[mid]){ // right side is sorted
                if (target < nums[mid] || target > nums[end]){
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
            }else{ // duplicate
                start++;
            }
        }
        return false;
    }
};
