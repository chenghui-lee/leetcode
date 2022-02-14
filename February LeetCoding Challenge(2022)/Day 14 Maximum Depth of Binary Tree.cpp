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
    
    void dfs(TreeNode* node, int depth){
        if (!node) return;
        res = max(res, depth);
        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }
    int maxDepth(TreeNode* root) {
        dfs(root, 1);
        return res;
    }
};
