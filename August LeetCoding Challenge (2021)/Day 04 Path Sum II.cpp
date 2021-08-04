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
    vector<vector<int>> res;
    
    void dfs(TreeNode* root, vector<int>& path, int sum, int target){
        if(!root) return;
        path.push_back(root->val);
        if (!root->left && !root->right && sum + root->val == target){
            res.push_back(path);
        }
        dfs(root->left, path, sum+root->val, target);
        dfs(root->right, path, sum+root->val, target);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, path, 0, targetSum);
        return res;
    }
};
