// https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/discuss/214216/JavaC%2B%2BPython-DFS-Solution
class Solution {
public:
    vector<int> res;
    int index = 0;
    bool dfs(TreeNode* node, vector<int>& v){
        if (!node) return true;
        if (node->val != v[index++]) return false;
        
        if (node->left && node->left->val != v[index]){
            res.push_back(node->val);
            return dfs(node->right, v) && dfs(node->left, v); // swapped
        }
        return dfs(node->left, v) && dfs(node->right, v);
    }
    
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        bool ok = dfs(root, voyage);
        if (ok) return res;
        else return vector<int>{-1};
    }
};
