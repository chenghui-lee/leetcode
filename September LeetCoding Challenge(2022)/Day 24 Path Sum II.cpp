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
    
    void dfs(TreeNode* root, int targetSum, int cur, vector<vector<int>>& res, vector<int>& temp){
        if (!root) return;
        cur += root->val;
        temp.push_back(root->val);
        
        if (!root->left && !root->right && cur == targetSum){
            res.push_back(temp);
            temp.pop_back();
            return;
        }
        dfs(root->left, targetSum, cur, res, temp);
        dfs(root->right, targetSum, cur, res, temp);
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(root, targetSum, 0, res, temp);
        return res;
    }
};
