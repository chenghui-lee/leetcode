class Solution {
public:
    vector<vector<int>> ans;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subsets;
        permute(nums, subsets, 0);
        return ans;
    }
    
    void permute(vector<int>& nums, vector<int>& subsets, int index){
        ans.push_back(subsets);
        for(int i=index; i<nums.size();i++){
            subsets.push_back(nums[i]);
            permute(nums, subsets, i+1);
            subsets.pop_back();
        }
    }
};
