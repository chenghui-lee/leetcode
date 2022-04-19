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

// O(N) time space
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        TreeNode curr = root;
        TreeNode pre;
        while (curr != null) {
            if (curr.left == null) {
                res.add(curr.val);
                curr = curr.right; // move to next right node
            } else { // has a left subtree
                pre = curr.left;
                while (pre.right != null) { // find rightmost
                    pre = pre.right;
                }
                pre.right = curr; // put cur after the pre node
                TreeNode temp = curr; // store cur node
                curr = curr.left; // move cur to the top of the new tree
                temp.left = null; // original cur left be null, avoid infinite loops
            }
        }
        return res;
    }
}
// O(N) time, O(1) space
// Moris traversal

class Solution {
public:
    // moris traversal
    /*
    Basic moris traversal idea (will change the order of the tree)
    
     1. Initialize current as root
     2. While current is not NULL
      If current does not have left child     
       a. Print current’s data
       b. Go to the right, i.e., current = current->right
      Else
       a. In current's left subtree, make current the right child of the rightmost node
       b. Go to this left child, i.e., current = current->left

     But this question requires us to maintain the tree structure, so we check the left rightmost node forming a cycle or not, if yes, change the child of the rightmost node back to NULL.
    */
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        TreeNode* prev = NULL;
        
        while(root){
            TreeNode* cur = root->left;
            
            if (cur){
                while(cur->right && cur->right != root){
                    cur = cur->right;
                }
                // first time access the node
                if (cur->right == NULL){
                    cur->right = root;
                    root = root->left;
                    continue;
                }else{ // visited here before, need to change back to null to restore the tree
                    cur->right = NULL;
                }
            }
            if (prev && root->val < prev->val){
                if (!first) first = prev;
                second = root;
            }
            prev = root;
            root = root->right;
        }
        swap(first->val, second->val);
        
    }
};
