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
    long dfs(TreeNode* root, long& total, unordered_set<long>& sum){
        if (!root) return 0;
        total += root->val;
        long cur = root->val + dfs(root->left, total, sum) + dfs(root->right, total, sum);
        sum.insert(cur);
        return cur;
    }    
    int maxProduct(TreeNode* root) {
        long total = 0, res = 0;
        unordered_set<long> sum;
        dfs(root, total, sum);
        
        for(auto& s : sum){
            res = max(res, (total - s) * s);
        }
        return res % int(1e9+7);
    }
};
