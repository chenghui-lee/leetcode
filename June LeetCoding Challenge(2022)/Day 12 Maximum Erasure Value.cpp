class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> s;
        int res = 0;
        int i = 0, j = 0, n = nums.size();
        int sum = 0;
        
        while(j < n){
            if (s.find(nums[j]) != s.end()){
                sum -= nums[i];
                s.erase(nums[i++]);
            }else{
                sum += nums[j];
                s.insert(nums[j++]);
                res = max(res, sum);
            }
        }
        return res;
    }
};
