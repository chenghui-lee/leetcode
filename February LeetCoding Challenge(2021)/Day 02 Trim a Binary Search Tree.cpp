class Solution {
public:
    TreeNode* dfs(TreeNode* node, int low, int high){
        if (!node) return NULL;
        
        if (node->val >= low && node->val <= high){
            node->left = dfs(node->left, low, high);
            node->right = dfs(node->right, low, high);
        }else if (node->val < low){
            node = dfs(node->right, low, high);
        }else{
            node = dfs(node->left, low, high);
        }
        return node;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        root = dfs(root, low, high);
        return root;
    }
};
