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
    unordered_map<int, int> m; // sum, frequency
    int res = 0;
    
    void dfs(TreeNode* root, int curSum, int target){
        if (!root) return;
        curSum += root->val;
        
        if (m.find(curSum - target) != m.end()){
            res += m[curSum - target];
        }
        m[curSum]++;
        dfs(root->left, curSum, target);
        dfs(root->right, curSum, target);
        m[curSum]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        m[0] = 1;    
        dfs(root, 0, targetSum);
        return res;
    }
};
