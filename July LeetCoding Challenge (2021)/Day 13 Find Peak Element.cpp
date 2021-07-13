class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        
        while(low < high){
            int mid = low + (high-low)/2;
            if ((mid >0 && mid <n && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) || (mid == 0 && nums[mid] > nums[mid+1]) || (mid == n-1 && nums[mid] > nums[mid-1])){
                return mid;
            }else if (mid > 0 && nums[mid] > nums[mid-1] || mid==0 && nums[mid] < nums[mid+1]) low = mid+1;
            else high = mid;
            
        }
        return low;
    }
};

// more simple binary search
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        while (l < r) {
            int mid = l + (r-l)/2;
            if (nums[mid] > nums[mid+1]) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        
        return l;
    }
};
