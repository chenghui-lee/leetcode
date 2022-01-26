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
    void dfs(TreeNode* node, vector<int>& v){
        if (!node) return;
        dfs(node->left, v);
        v.push_back(node->val);
        dfs(node->right, v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        dfs(root1, v1);
        dfs(root2, v2);
        
        vector<int> res;
        int i=0, j=0;
        
        while(i < v1.size() && j < v2.size()){
            if (v1[i] < v2[j]){
                res.push_back(v1[i++]);
            }else{
                res.push_back(v2[j++]);
            }
        }
        while(i < v1.size()) res.push_back(v1[i++]);
        while(j < v2.size()) res.push_back(v2[j++]);
        return res;
    }
};
