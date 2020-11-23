class Solution {
public:
    vector<int> helper(TreeNode* node){
        // res will be 2 element array [rob, not rob]
        if (!node) return {0,0};
        vector<int> left = helper(node->left);
        vector<int> right = helper(node->right);
        
        // if we rob this current house, we cant rob its children
        int rob = node->val + left[1] + right[1];
        // else we can either rob or not rob its children
        int not_rob = max(left[0], left[1]) + max(right[0], right[1]);
        
        return {rob, not_rob};
    }
    int rob(TreeNode* root) {
        vector<int> res = helper(root);
        return max(res[0], res[1]);
    }
};
