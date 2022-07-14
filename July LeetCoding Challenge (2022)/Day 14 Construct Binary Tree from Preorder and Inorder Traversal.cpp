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
    int preorderIndex;
    unordered_map<int, int> inorderIndexMap;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIndex = 0;
        for(int i=0; i<inorder.size(); i++){
            inorderIndexMap[inorder[i]] = i;
        }
        return helper(preorder, 0, preorder.size()-1);
    }
    
    TreeNode* helper(vector<int>& preorder, int left, int right){
        if (left > right) return NULL;
        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);
        
        root->left = helper(preorder, left, inorderIndexMap[rootVal] - 1);
        root->right = helper(preorder, inorderIndexMap[rootVal] + 1, right);
        return root;
    }
    
};
