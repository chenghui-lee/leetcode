// O(n) time space
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
private:
    TreeNode* helper(vector<int>& preorder, int& idx, int limit){
        if (idx == preorder.size() || preorder[idx] > limit){
            return NULL;
        }
        int root_val = preorder[idx++];
        TreeNode* root = new TreeNode(root_val);
        root->left = helper(preorder, idx, root_val);
        root->right = helper(preorder, idx, limit);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return helper(preorder, index, INT_MAX);
    }
};
