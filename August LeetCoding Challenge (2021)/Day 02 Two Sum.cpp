class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m; // bal , index
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            if (m.find(nums[i]) != m.end()){
                return {m[nums[i]], i};
            }else{
                m[target - nums[i]] = i;
            }    
        }
        return {-1, -1};
    }
};
