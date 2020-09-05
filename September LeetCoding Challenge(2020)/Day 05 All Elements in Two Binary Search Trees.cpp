// 828ms, not efficient, will upload more efficient way in the future

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
    vector<int> res;
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        dfs(root1, true);
        dfs(root2, true);
        sort(res.begin(), res.end());
        return res;
    }
    void dfs(TreeNode* node, bool left){
        if(!node) return;
        if(left) res.insert(res.begin(), node->val);
        else res.push_back(node->val);
        dfs(node->left, true);
        dfs(node->right, false);
        
    }
};
