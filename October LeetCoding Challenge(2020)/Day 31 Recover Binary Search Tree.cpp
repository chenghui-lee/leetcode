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
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* prev = new TreeNode(INT_MIN);
    
    void dfs(TreeNode* node){
        if(!node) return;
        dfs(node->left);
        if(!first && prev->val > node->val){ // prev is the node below, aka children
            first = prev;
        }
        if (first && prev->val > node->val){
            second = node;
        }
        prev = node;
        dfs(node->right);
    }    
    
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(first->val, second->val);
    }
};
