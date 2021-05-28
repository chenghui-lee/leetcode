// sliding windows, two pointers
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> s;
        int i = 0, j = 0, sum = 0, res = 0;
        int n = nums.size();
        while(i < n && j < n){
            if (s.find(nums[j]) == s.end()){
                sum += nums[j];
                res = max(res, sum);
                s.insert(nums[j++]);
            }else {
                sum -= nums[i];
                s.erase(nums[i++]);
            }
        }
        return res;
    }
};
