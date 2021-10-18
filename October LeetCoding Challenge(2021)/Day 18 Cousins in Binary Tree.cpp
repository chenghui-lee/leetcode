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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            int match = 0;
            for(int i=0; i<sz; i++){
                auto cur = q.front(); q.pop();
                if (cur->val == x || cur->val == y) match++;
                if (cur->left && cur->right){
                    if (cur->left->val == x && cur->right->val == y ||
                       cur->left->val == y && cur->right->val == x){
                        return false;    
                    }
                }
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            if (match > 0 && match == 2) return true;
            else if (match > 0) return false;
        }
        return false;
    }
};
