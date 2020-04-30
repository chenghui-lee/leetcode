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
 
 // it is a valid sequence if the path is from root node to any leaf node
 // so we got 2 cases,
 // first, if the node itself is null or the node value is not same with the value in array, return false
 // second, if we reach the last element in array, we check the node is a leaf or not (left right both null)
 // do this recursively by checking the left side and right side (dfs), if any side matches the arr, then we continue.
 
class Solution {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return dfs(root, arr, 0);
    }
    bool dfs(TreeNode *node, vector<int> &arr, int position){
        if (node == NULL || node->val != arr[position]){ // if the node is null or the value of the node is not same with the array
            return false;
        }
        if (position == arr.size() -1){ // check the node is leaf or not
            return node->left == NULL && node->right == NULL;
        }
        return dfs(node->left, arr, position + 1) or dfs(node->right, arr, position + 1); // either one side
    }
};
