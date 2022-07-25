class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        res[0] = findFirst(nums, target);
        res[1] = findLast(nums, target);
        return res;
    }
    int findFirst(vector<int>& nums, int target){
        int idx = -1;
        int i = 0, j = nums.size() - 1;
        
        while(i <= j){
            int mid = i + (j-i) / 2;
            if (nums[mid] < target) i = mid + 1;
            else if (nums[mid] > target) j = mid - 1;
            else{
                idx = mid; // this might be the first occurance, or not
                j = mid - 1; // search for the next possible index at [0, mid-1];
            }
        }
        return idx;
    }
    int findLast(vector<int>& nums, int target){
        int idx = -1;
        int i = 0, j = nums.size() - 1;
        
        while(i <= j){
            int mid = i + (j-i) / 2;
            if (nums[mid] < target) i = mid + 1;
            else if (nums[mid] > target) j = mid - 1;
            else{
                idx = mid; // this might be the last occurance, or not
                i = mid + 1; // search for the next possible index at [mid+1, n-1];
            }
        }
        return idx;
    }
};
