class Solution {
public:
    int sum = 0;
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        dfs(root, "");
        return sum;
    }
    void dfs(TreeNode *node, string parent){
        if(!node) return;
        string s = parent + to_string(node->val);
        if(!node->left && !node->right){
            sum += stoi(s); // to int
        }
        if (node->left) dfs(node->left, s);
        if (node->right) dfs(node->right, s);
    }
};

// another solution
class Solution {
public:
    void sumNumbersHelper(TreeNode* root, int cur, int& res) {
        if(root==nullptr)
            return;
        cur=cur*10+root->val;
        if(root->left==nullptr && root->right==nullptr) {
            res+=cur;
            return;
        }
        sumNumbersHelper(root->left, cur, res);
        sumNumbersHelper(root->right, cur, res);
    }
    int sumNumbers(TreeNode* root) {
        int res=0;
        sumNumbersHelper(root, 0, res);
        return res;
    }
};
