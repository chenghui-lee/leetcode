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
    TreeNode* dfs(TreeNode* root, int low, int high){
        if (!root) return NULL;
        
        if (root->val >= low && root->val <= high){
            root->left = dfs(root->left, low, high);
            root->right = dfs(root->right, low, high);
        }else if (root->val > high){
            root = dfs(root->left, low, high);
        }else{
            root = dfs(root->right, low, high);
        }
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return dfs(root, low, high);
    }
};
