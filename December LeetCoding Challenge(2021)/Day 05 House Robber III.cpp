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
    vector<int> dfs(TreeNode* node){
        // [rob, not rob]
        if (!node) return {0, 0};
        vector<int> left = dfs(node->left);
        vector<int> right = dfs(node->right);
        
        int rob = node->val + left[1] + right[1];
        int notrob = max(left[0], left[1]) + max(right[0], right[1]);
        return {rob, notrob};
    }
    int rob(TreeNode* root) {
        vector<int> res = dfs(root);
        return max(res[0], res[1]);
    }
};
