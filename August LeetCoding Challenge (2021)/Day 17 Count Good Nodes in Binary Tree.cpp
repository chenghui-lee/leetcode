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
    void dfs(TreeNode* root, int parMax){
        if (!root) return;
        if (parMax <= root->val) res++;
        parMax = max(parMax, root->val);
        dfs(root->left, parMax);
        dfs(root->right, parMax);
        
    }
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return res;
    }
};
