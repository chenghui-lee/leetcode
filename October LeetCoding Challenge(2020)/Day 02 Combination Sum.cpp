class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        dfs(candidates, target, 0, res, temp);
        return res;
    }
    void dfs(vector<int>& candidates, int target, int start, vector<vector<int>>& res, vector<int>& temp){
        if (target == 0){
            res.push_back(temp);
            return;
        }
        for(int i=start; i<candidates.size(); i++){
            if (candidates[i] > target) break;
            temp.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, res, temp); // not i + 1 because can use back same element
            temp.pop_back();
        }
    }
};
