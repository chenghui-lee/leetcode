class Solution {
public:
    int findMin(vector<int>& nums) {
        int m = INT_MAX;
        for(auto x : nums){
            m = min(x, m);
        }
        return m;
    }
};

// binary search

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while(low < high){
            int mid = low + (high-low)/2;
            if(nums[mid] > nums[high]){
                low = mid + 1;
            }else if (nums[mid] < nums[high]){
                high = mid;
            }else{
                high--;
            }
        }
            
        return nums[low];
    }
};
