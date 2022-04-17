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
    map<int, int> m;
    void dfs(TreeNode* node){
        if(!node) return;
        m[node->val]++;
        dfs(node->left);
        dfs(node->right);
        
    }
    TreeNode* increasingBST(TreeNode* root) {
        dfs(root);
        TreeNode* head = new TreeNode();
        TreeNode* cur = head;
        for(auto x : m){
            int count = x.second;
            while(count--){
                cur->right = new TreeNode(x.first);
                cur = cur->right;
            }
        }
        return head->right;
    }
};
