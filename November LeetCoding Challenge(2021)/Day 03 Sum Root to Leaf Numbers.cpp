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
    int res = 0;
    void dfs(TreeNode* root, int& sum){
        if (!root) return;
        sum = sum * 10 + root->val;
        if (!root->left && !root->right){
            res += sum;
            sum /= 10;
            return;
        }
        dfs(root->left, sum);
        dfs(root->right, sum);
        sum /= 10;
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return res;
    }
};
