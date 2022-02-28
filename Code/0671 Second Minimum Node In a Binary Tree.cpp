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
    int dfs(TreeNode* root, int val){
        if (!root) return -1;
        if (root->val != val) return root->val;
        int left = dfs(root->left, val);
        int right = dfs(root->right, val);
        if (left == -1 || right == -1) return max(left, right);
        else return min(left, right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        int res = dfs(root, root->val);
        if (root && res == root->val) res = -1;
        return res;
    }
};
