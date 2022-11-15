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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int left = countLeft(root);
        int right = countRight(root);
        
        // if left == right, return 2^height - 1
        if (left == right){
            return (2 << left) - 1;
        }else{ // left + right + root
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
    int countLeft(TreeNode* root){
        int count = 0;
        while(root->left){
            count++;
            root = root->left;
        }
        return count;
    }
    int countRight(TreeNode* root){
        int count = 0;
        while(root->right){
            count++;
            root = root->right;
        }
        return count;
    }
};
