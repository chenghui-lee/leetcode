class Solution {
public:
    
    void dfs(vector<int>& candidates, vector<vector<int>>& res, vector<int>& cur, int target, int start){
        if (target == 0){
            res.push_back(cur);
            return;
        }
        for(int i=start; i<candidates.size(); i++){
            if (candidates[i] > target) break;
            cur.push_back(candidates[i]);
            dfs(candidates, res, cur, target - candidates[i], i);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, res, cur, target, 0);
        return res;
    }
};
