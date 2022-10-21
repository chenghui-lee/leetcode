class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> idx; // num, most recent index
        for(int i=0; i<nums.size(); i++){
            if (idx.find(nums[i]) != idx.end() &&  i - idx[nums[i]] <= k){
                return true;
            }
            idx[nums[i]] = i;
        }
        return false;
    }
};
