class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        dfs(root, 0);
        reverse(res.begin(), res.end());
        return res;
    }
    void dfs(TreeNode *node, int depth){
        if (!node) return;
        if (depth==res.size()){
            res.push_back({});
        }
        res[depth].push_back(node->val);
        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }
};
