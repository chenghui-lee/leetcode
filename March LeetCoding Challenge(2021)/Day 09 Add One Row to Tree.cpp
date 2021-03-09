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

// @dreamchase, https://leetcode.com/problems/add-one-row-to-tree/discuss/104547/Java-three-methods-one-BFS-and-two-DFS
class Solution {
public:
    void dfs(TreeNode* node, int depth, int v, int target){
        if (!node) return;
        if (depth < target-1){
            dfs(node->left, depth+1, v, target);
            dfs(node->right, depth+1, v, target);
        }else{
            auto temp = node->left;
            node->left = new TreeNode(v);
            node->left->left = temp;
            temp = node->right;
            node->right = new TreeNode(v);
            node->right->right = temp;
        }
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1){
            auto newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        } 
        dfs(root, 1, v, d);
        return root;
    }
};
