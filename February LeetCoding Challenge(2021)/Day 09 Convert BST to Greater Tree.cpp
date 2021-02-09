class Solution {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return root;
        convertBST(root->right);
        sum += root->val;
        root->val = sum;
        convertBST(root->left);
        return root;
    }
};
