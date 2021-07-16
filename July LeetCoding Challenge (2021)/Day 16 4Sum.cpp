// applicable to kSum
class Solution {
private:
    vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k){
        vector<vector<int>> res;
        if (start == nums.size() || nums[start] * k > target || target > nums.back() * 4){
            return res;
        }
        if (k == 2){
            return twoSum(nums, target, start);
        }
        for(int i = start; i<nums.size(); i++){
            if (i == start || nums[i] != nums[i-1]){
                for(auto& set : kSum(nums, target - nums[i], i+1, k-1)){
                    set.push_back(nums[i]);
                    res.push_back(set);
                    // res.push_back({nums[i]});
                    // res.back().insert(end(res.back()), begin(set), end(set));
                }
            }
        }
        return res;
    }
    
    vector<vector<int>> twoSum(vector<int>& nums, int target, int start){
        vector<vector<int>> res;
        int low = start, high = nums.size() -1;
        
        while(low < high){
            int sum = nums[low] + nums[high];
            if (sum < target || (low > start && nums[low-1] == nums[low])) low++;
            else if (sum > target || (high < nums.size()-1 && nums[high] == nums[high+1])) high--;
            else res.push_back({nums[low++], nums[high--]});
        }
        return res;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
    }
};
