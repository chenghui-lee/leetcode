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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        int i = 1;
        while (i<preorder.size() && preorder[i]<root->val){
            i++;
        }
        auto it = preorder.begin() + i;
        vector<int> l(preorder.begin()+1, it);
        vector<int> r(it, preorder.end());
        root->left = bstFromPreorder(l);
        root->right = bstFromPreorder(r);
        return root;
    }
};
