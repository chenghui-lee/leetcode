// 
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
 //https://leetcode.com/problems/kth-smallest-element-in-a-bst/discuss/641709/Concise-Explanation-w-code-or-0-ms-or-100-faster
class Solution {
public:
    int count, res;
    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        inOrder(root, k);
        return res;
    }
    void inOrder(TreeNode *node, int k){
        if (!node) return;
        inOrder(node->left, k);
        count++;
        if (count == k){
            res = node->val;
            return;
        }
        inOrder(node->right, k);
    }
    
};
