// Idea by lee215

/*
if root == null,
return pair(0, null)

if left depth == right depth,
deepest nodes both in the left and right subtree,
return pair (left.depth + 1, root)

if left depth > right depth,
deepest nodes only in the left subtree,
return pair (left.depth + 1, left subtree)

if left depth < right depth,
deepest nodes only in the right subtree,
return pair (right.depth + 1, right subtree)

*/
class Solution {
public:
    pair<int, TreeNode*> dfs(TreeNode* node){ // depth, Node that has the deepest depth
        if(!node) return {0, NULL};
        auto l = dfs(node->left);
        auto r = dfs(node->right);
        
        return {max(l.first, r.first) + 1, l.first == r.first ? node: l.first > r.first ? l.second : r.second};
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};
