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
    void dfs(TreeNode* root, int curSum, unordered_set<int>& s) {
        curSum += root->val;
        if (!root->left && !root->right) {
            s.insert(curSum);
            return;
        }
        if (root->left) dfs(root->left, curSum, s);
        if (root->right) dfs(root->right, curSum, s);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
       unordered_set<int> s;
       dfs(root, 0, s); 
       return s.find(targetSum) != s.end();
    }
};
