// Approach 1
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
    vector<int> prefixSum;
    unordered_map<int, int> m; // num, idx
    
    void dfs(TreeNode* root){
        if (!root) return;
        dfs(root->left);
        m[root->val] = prefixSum.size();
        if (prefixSum.empty()) prefixSum.push_back(root->val);
        else{
            prefixSum.push_back(prefixSum.back() + root->val);
        }
        dfs(root->right);
    }
    TreeNode* reconstruct(TreeNode* root){
        if (!root) return NULL;
        root->val = prefixSum.back() - prefixSum[m[root->val]] + root->val;
        reconstruct(root->left);
        reconstruct(root->right);
        return root;
    }
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return reconstruct(root);
    }
};


// Approach 2
class Solution {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return NULL;
        convertBST(root->right);
        
        sum += root->val;
        root->val = sum;
        
        convertBST(root->left);
        return root;
    }
};
