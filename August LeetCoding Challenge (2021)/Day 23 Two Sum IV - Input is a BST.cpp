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
    bool findTarget(TreeNode* root, int k) {
        queue<TreeNode*> q;
        unordered_set<int> needed;
        
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto cur = q.front(); q.pop();
                if (needed.find(cur->val) != needed.end()) return true;
                needed.insert(k - cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        
        return false;
    }
};

// another way, in order
class Solution {
public:
    void inorder(vector<int>& num, TreeNode* root){
        if (!root) return;
        inorder(num, root->left);
        num.push_back(root->val);
        inorder(num, root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> num;
        inorder(num, root);
        int i = 0, j = num.size() - 1;
        
        while(i < j){
            int sum = num[i] + num[j];
            if (sum == k) return true;
            else if (sum > k) j--;
            else i++;
        }
        return false;
    }
};
