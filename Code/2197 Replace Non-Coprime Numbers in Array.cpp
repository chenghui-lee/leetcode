// simulate the entire process
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for(int i=0; i<n; i++){
            while(!res.empty() && __gcd(res.back(), nums[i]) > 1){
                long long last = res.back(); res.pop_back();
                nums[i] = (last * nums[i]) / __gcd((int)last, nums[i]); // replace with lcm
            }
            res.push_back(nums[i]);
        }
        return res;
    }
};
