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
    bool ok = true;
    int dfs(TreeNode* root, int depth){
       if (!root) return depth - 1;
        int left = dfs(root->left, depth+1);
        int right = dfs(root->right, depth+1);
        if (abs(left - right) > 1) ok = false;
        return max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int left = dfs(root->left, 1);
        int right = dfs(root->right, 1);
        return abs(left - right) <= 1 && ok;
    }
};
