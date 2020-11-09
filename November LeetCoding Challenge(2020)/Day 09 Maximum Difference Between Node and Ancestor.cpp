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
    
    int helper(TreeNode* node, int maxx, int minn){
        if (!node) return maxx - minn;
        maxx = max(maxx, node->val);
        minn = min(minn, node->val);
        return max(helper(node->left, maxx, minn), helper(node->right, maxx, minn));
    }
    
    int maxAncestorDiff(TreeNode* root) {
        return helper(root, root->val, root->val);
    }
};
