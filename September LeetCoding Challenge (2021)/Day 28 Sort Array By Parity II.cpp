class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int odd = 1, even = 0, n = nums.size();
        
        while(odd < n && even < n){
            while(even < n && nums[even] % 2 == 0){
                even += 2;
            }
            while(odd < n && nums[odd] % 2 == 1){
                odd += 2;
            }
            if (even < n && odd < n) swap(nums[odd], nums[even]);
        }
        return nums;
    }
};
