/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int dia = 0;
int maxDepth(TreeNode *node){ // int& pass by reference
    if (!node){
      return 0;
    }
    int left = maxDepth(node->left);
    int right = maxDepth(node->right);
    dia = max(left+right, dia);
    return max(left, right) + 1;

}

int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return dia;
}
};
