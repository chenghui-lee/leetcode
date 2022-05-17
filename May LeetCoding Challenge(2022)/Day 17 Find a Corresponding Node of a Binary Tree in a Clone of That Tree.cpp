/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* dfs(TreeNode* ori, TreeNode* copy, TreeNode* target){
        if (!ori) return NULL;
        
        if (ori == target) return copy;
        TreeNode* left = dfs(ori->left, copy->left, target);
        TreeNode* right = dfs(ori->right, copy->right, target);
        if (left) return left;
        else if (right) return right;
        else return NULL;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return dfs(original, cloned, target);
    }
};
