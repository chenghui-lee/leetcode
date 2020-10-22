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
    int dfs(TreeNode* node, int sum){
        if(!node) return 0;
        if(!node->left && !node->right) return sum;
        if (!node->left) return dfs(node->right, sum+1);
        else if (!node->right) return dfs(node->left, sum+1);
        else return min(dfs(node->right, sum+1), dfs(node->left, sum+1));
        
    }
    int minDepth(TreeNode* root) {
        return dfs(root, 1);
    }
};

// another solution
public:
    int helper(TreeNode* root){
        if(!root)
            return 0;
        if(!root->left)
            return 1 + helper(root->right);
        if(!root->right)
            return 1 + helper(root->left);
        return 1 + min(helper(root->right), helper(root->left));
    }        
    
    int minDepth(TreeNode* root) {
        return helper(root);
    }
