class Solution {
public:
    vector<vector<int>> res;
    void dfs(int n, int k, int index, vector<int>& cur){
        if (k == 0){
            if (n == 0) res.push_back(cur);
            return;
        }
        for(int i=index; i<=9; i++){
            if (i > n) return;
            cur.push_back(i);
            dfs(n-i, k-1, i+1, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cur;
        dfs(n, k, 1, cur);
        return res;
    }
};
