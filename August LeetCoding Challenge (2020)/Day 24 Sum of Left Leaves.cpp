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
    int sum;
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root,false);
        return sum;
    }
    
    void dfs(TreeNode* node, bool isLeft){
        if(!node) return;
        if(!node->left && !node->right && isLeft) sum+=node->val;
        dfs(node->left, true);
        dfs(node->right, false);
    }
};
