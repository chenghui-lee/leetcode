class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& cur, int idx){
        res.push_back(cur);
        for(int i=idx; i<nums.size(); i++){
            cur.push_back(nums[i]);
            dfs(res, nums, cur, i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(res, nums, cur, 0);
        
        return res;
    }
};
