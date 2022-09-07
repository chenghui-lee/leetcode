// https://leetcode.com/problems/construct-string-from-binary-tree/discuss/2542523/LeetCode-The-Hard-Way-DFS-or-5-Cases-or-Explained-Line-By-Line
 */
// Time Complexity: O(N) where N is the number of the nodes in the tree
// Space Complexity: O(H) where H is the height of the tree. 
// In worse case, H can be N when it is a left skewed binary tree / right skewed binary tree
class Solution {
public:
    // case 1: root is nullptr -> ""
    // case 2: root doesn't have left sub tree and right sub tree -> root->val
    // case 3: root->left is not nullptr -> root->val + (dfs result from left sub tree)
    // case 4: root->left is nullptr but root->right is not nullptr -> root->val + () 
    // case 5: root->right is not nullptr -> root->val + (dfs result from right sub tree)
    string tree2str(TreeNode* root) {
        // handle case 1
        if (!root) return "";
        // we convert root->val to string here, then append results from different cases
        string s = to_string(root->val);
        // handle case 2
        // this line is obviously not necessary
        if (!root->left && !root->right) s += "";  
        // handle case 3
        if (root->left) s += "(" + tree2str(root->left) + ")";
        // handle case 4
        // alternatively, you can use `else if (root->right) s += "()";`
        if (!root->left && root->right) s += "()";
        // handle case 5
        if (root->right) s += "(" + tree2str(root->right) + ")";
        return s;
    }
};
