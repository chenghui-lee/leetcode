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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0 || inorder.size() != postorder.size()) return NULL;
        return helper(inorder, postorder, 0, 0, inorder.size());
    }
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int in_start, int po_start, int size){
        if(size==0) return NULL;
        TreeNode* root = new TreeNode(postorder[po_start + size - 1]);
        // root->val = (); // last element
        int index = in_start;
        while(inorder[index] != postorder[po_start + size - 1]) index++;
        int leftSize = index - in_start;
        int rightSize = size - leftSize - 1;
        root->left = helper(inorder, postorder, in_start, po_start, leftSize);
        root->right = helper(inorder, postorder, index+1, po_start+leftSize, rightSize);
        return root;
    }
};
