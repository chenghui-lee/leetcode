class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        
        if (!root) return res;
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* cur = q.front();
                q.pop();
                if (i == n-1) res.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return res;
    }
};
