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
    
    void dfs(vector<int>& nums, TreeNode* root){
        if (!root) return;
        dfs(nums, root->left);
        nums.push_back(root->val);
        dfs(nums, root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> nums;
        dfs(nums, root);
        for(int i=1; i<nums.size(); i++){
            if (nums[i] <= nums[i-1]) return false;
        }
        return true;
    }
};
