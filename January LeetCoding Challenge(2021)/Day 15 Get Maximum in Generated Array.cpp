class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0 || n == 1) return n;
        
        vector<int> nums(n+1);
        nums[0] = 0; nums[1] = 1;
        for(int i=0; i<=n; i++){
            if (2*i <= n){
                nums[2*i] = nums[i];
            }
            if (2*i + 1 <=n){
                nums[2*i+1] = nums[i] + nums[i+1];
            }
        }
        return *max_element(nums.begin(), nums.end());
    }
};
