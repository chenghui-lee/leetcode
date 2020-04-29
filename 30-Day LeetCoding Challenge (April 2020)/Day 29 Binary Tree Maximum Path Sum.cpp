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
    int result;
public:
    int maxPathSum(TreeNode* root) {
        result = INT_MIN;
        sum(root);
        return result;
    }
    int sum(TreeNode* root){
        if (root == NULL){
            return 0;
        }
        int left = max(0, sum(root->left));
        int right = max(0, sum(root->right));
        result = max(result, left+right+root->val);
        return max(left, right) + root->val;
    }
    
};

// another solution with O(n) time 
// https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/602931/C%2B%2B-or-O(n)-Recursive-or-Short-and-Easy-to-understand-with-comment
class Solution {
    int helper( TreeNode* node, int &maxSum ) {
        if( !node ) return 0;
        int left = 0, right = 0;
        if( node->left )  left = helper( node->left, maxSum );
        if( node->right ) right = helper( node->right, maxSum );
        
        // node+left or node+right or node
        int leftOrRightOrNode = max( node->val, node->val + max( left, right ) );
        // set maxSum to max of maxSum, node+left+right, node+left, node+right, node
        maxSum = max( maxSum, max( node->val + left + right, leftOrRightOrNode ) );        
        return leftOrRightOrNode;
    }
    
public:
    int maxPathSum( TreeNode* root ) {
        int maxSum = INT_MIN;
        helper( root, maxSum );
        return maxSum;
    }
};
