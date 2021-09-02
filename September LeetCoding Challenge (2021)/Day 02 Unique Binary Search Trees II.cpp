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
    vector<TreeNode*> helper(int start, int end){
        vector<TreeNode*> res;
        if (start > end){
            res.push_back(NULL);
            return res;
        }
        
        for(int i=start; i<=end; i++){
            auto leftNodes = helper(start, i-1);
            auto rightNodes = helper(i+1, end);
            
            for(auto left : leftNodes){
                for(auto right : rightNodes){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
};
