class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(q.size()){
            int sz = q.size();
            double sum = 0;
            for(int i=0; i<sz; i++){
                auto cur = q.front();
                q.pop();
                sum += cur->val;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            res.push_back(sum / sz);
        }
        return res;
    }
};
