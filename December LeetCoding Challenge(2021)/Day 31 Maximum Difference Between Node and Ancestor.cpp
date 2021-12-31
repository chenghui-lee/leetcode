/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = 0;
    void dfs(TreeNode* root, int mx, int mn){
        if (!root) return;
        res = max(max(res, abs(mx-root->val)), abs(mn-root->val));
        dfs(root->left, max(mx, root->val), min(mn, root->val));
        dfs(root->right, max(mx, root->val), min(mn, root->val));
    }
    
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return res;
    }
};
