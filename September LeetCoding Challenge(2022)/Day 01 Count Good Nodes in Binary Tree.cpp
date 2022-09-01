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
    void dfs(TreeNode* cur, int maxSoFar, int& res){
        if (!cur) return;
        if (cur->val >= maxSoFar) res++;
        maxSoFar = max(maxSoFar, cur->val);
        dfs(cur->left, maxSoFar, res);
        dfs(cur->right, maxSoFar, res);
    }
    int goodNodes(TreeNode* root) {
        int res = 0;
        dfs(root, root->val, res);
        return res;
    }
};
