/*

Say we have 2 arrays, PRE and IN.
Preorder traversing implies that PRE[0] is the root node.
Then we can find this PRE[0] in IN, say it's IN[5].
Now we know that IN[5] is root, so we know that IN[0] - IN[4] is on the left side, IN[6] to the end is on the right side.
Recursively doing this on subarrays, we can build a tree out of it
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34538/My-Accepted-Java-Solution
 */
class Solution {
public:
    unordered_map<int, int> m;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++){
            m[inorder[i]] = i;
        }
        return build(preorder, 0, 0, inorder.size()-1);
    }
    
    TreeNode* build(vector<int>& preorder, int preStart, int inStart, int inEnd){
        if (preStart >= preorder.size() || inStart > inEnd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        int idx = m[preorder[preStart]];
        root->left = build(preorder, preStart+1, inStart, idx-1);
        root->right = build(preorder, preStart + 1 + idx - inStart, idx+1, inEnd);
        return root;
    }
};
