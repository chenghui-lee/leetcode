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
    int count = 0;
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        TreeNode * cur = root;
        dfs(cur);
        return count;
    }
    void dfs(TreeNode * node){
        if (node == NULL) return;
        count ++;
        dfs(node->left);
        dfs(node->right);
    
    }
};
