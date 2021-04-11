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
    map<int, vector<int>> m;
    void dfs(TreeNode* node, int depth){
        if (!node) return;
        m[depth].push_back(node->val);
        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        auto mx = (m.rbegin())->second;
        return accumulate(mx.begin(), mx.end(), 0);
    }
};
