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
    
    void dfs(TreeNode* node, vector<int> num){
        if (!node) return;
        num[node->val]++;
        dfs(node->left, num);
        dfs(node->right, num);
        
        if (!node->left && !node->right){
            int odd = 0;
            for(auto x : num){
                if (x%2) odd++;
            }
            if (odd <= 1) res++;
        } 
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> num(10);
        dfs(root, num);
        return res;
    }
};
