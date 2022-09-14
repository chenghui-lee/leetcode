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
    
    void dfs(TreeNode* root, int& res, unordered_map<int,int>& count) {
        if (!root) return;
        count[root->val]++;
        dfs(root->left, res, count);
        dfs(root->right, res, count);
        
        // if is leaf node
        if (!root->left && !root->right){
            int odd = 0;
            for(auto x : count){
                odd += x.second % 2;
            }
            if (odd <= 1) res++;
        }
        count[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> count; // num, frequency
        int res = 0;
        dfs(root, res, count);
        return res;
    }
};
