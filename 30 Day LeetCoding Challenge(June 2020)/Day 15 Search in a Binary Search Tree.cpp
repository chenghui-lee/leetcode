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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL || root->val == val) return root;
        return helper(root, val);      
    }
    
    TreeNode* helper(TreeNode* node, int val){
        if (node == NULL) return NULL;
        else if (node->val > val) return helper(node->left, val);
        else if (node->val < val) return helper(node->right, val);
        else return node;
    }
};
