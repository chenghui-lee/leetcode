class Solution {
public:
    long long sum(long long start, long long end){
        if (end < start) return 0;
        long long res = ((end * (end + 1)) - (start * (start - 1))) / 2 ;
        return res;
    }
    
    long long minimalKSum(vector<int>& nums, int k) {
        long long res = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        long long tmp;
        tmp = sum(1, nums[0]-1);
        if (tmp > 0){
            if (k <= nums[0] - 1){
                res += sum(1, 0+k);
                k = 0;
            }else{
                res += tmp;
                k -= nums[0] - 1;
            }
        }
        for(int i=0; i<n-1 && k > 0 ; i++){
            if (nums[i]+1 >= nums[i+1]) continue;
            tmp = sum(nums[i]+1, nums[i+1]-1);
            if (tmp > 0){
                if (k >= nums[i+1] - nums[i] - 1){
                    k -= nums[i+1] - nums[i] - 1;
                    res += tmp;
                }else{
                    res += sum(nums[i]+1, nums[i]+k);
                    k = 0;
                }
            }
        }
        if (k > 0){
            res += sum(nums.back()+1, nums.back()+k);
        }
        
        return res;
    }
};
