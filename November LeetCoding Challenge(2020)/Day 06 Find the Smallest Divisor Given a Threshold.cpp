class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int high = nums[n-1], low = 1;
        
        int sum = 0;
        while(low < high){
            int mid = low + (high-low)/2;
            sum = 0;
            for(int x : nums){
                sum += (x + mid - 1)/mid; // can use ceil(x/mid) too
            }
            if (sum > threshold) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};
