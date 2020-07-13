class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return compare(p, q);
    }
    bool compare(TreeNode* a, TreeNode* b){
        if (!a && !b) return true;
        else if (!a || !b) return false;
        bool center = a->val == b->val;
        if (!center) return false;
        
        bool l = compare(a->left, b->left);
        bool r = compare(a->right, b->right);
        return l && r;
        
    }
};
