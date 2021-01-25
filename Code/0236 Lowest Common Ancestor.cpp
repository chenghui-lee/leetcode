class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (!left){
            return right;
        }else if (!right){
            return left;
        }else{
            return root;
        }
    }
};

// Solution 2

class Solution {
public:
    TreeNode* res = NULL;
    
    bool dfs(TreeNode* node, TreeNode* p, TreeNode* q){
        if (!node) return false;
        
        int left = dfs(node->left, p, q);
        int right = dfs(node->right, p, q);
        
        int mid = (node==p || node==q);
        
        if (left + right + mid >= 2){
            res = node;
        }
        return left + right + mid > 0;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return res;
        
    }
};
