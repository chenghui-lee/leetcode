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
    int sum = 0;
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }
    void dfs(TreeNode* node, int parent){
        if(!node) return;
        if(!node->left && !node->right){
            sum += (parent << 1) + node->val;
            return;
         }
        dfs(node->left, (parent << 1) + node->val);
        dfs(node->right, (parent << 1) + node->val);
    }
};
