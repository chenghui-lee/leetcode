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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        root = dfs(root, val);
        return root;
    }
    TreeNode* dfs(TreeNode* node, int val){
        if(!node) return new TreeNode(val);
        if (node->val > val){
            node->left = dfs(node->left, val);
        }else{
            node->right = dfs(node->right, val);
        }
        return node;
    }
};
