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
class BSTIterator {
private:
    
    void dfs(TreeNode* node){
        if (!node) return;
        s.insert(node->val);
        dfs(node->left);
        dfs(node->right);
    }
public:
    
    multiset<int> s;
    multiset<int>::iterator it;
    
    BSTIterator(TreeNode* root) {
        dfs(root);
        it = s.begin();
        
    }
    
    int next() {
        int res = *it;
        ++it;
        return res;
    }
    
    bool hasNext() {        
        return it != s.end(); 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
