class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto f = find(nums.begin(), nums.end(), target);
        if(f != nums.end()) return f - nums.begin();
        auto x = upper_bound(nums.begin(), nums.end(), target);
        return x - nums.begin();
    }
};
// binary search
  int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while (l<=r){
            int mid = l + (r-l)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) r = mid-1;
            else l = mid+1;
        }
        return l;
    }
