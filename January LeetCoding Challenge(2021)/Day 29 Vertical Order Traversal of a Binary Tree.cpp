class Solution {
public:
    static bool cmp(pair<TreeNode*, int> a, pair<TreeNode*, int> b){
        return a.first->val < b.first->val;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> m;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        
        while(!q.empty()){
            int sz = q.size();
            vector<pair<TreeNode*, int>> temp;
            for(int i=0; i<sz; i++){           
                auto [cur,x] = q.front();
                q.pop();
                m[x].push_back(cur->val);
                if(cur->left) temp.push_back({cur->left, x-1});
                if(cur->right) temp.push_back({cur->right, x+1});
            }
            // sort(temp.begin(), temp.end(), [](pair<TreeNode*, int> a, pair<TreeNode*, int> b){return a.first->val < b.first->val;}); // with lambda expression
            sort(temp.begin(), temp.end(), cmp);
            for(auto t:temp) q.push(t);
        }     
        vector<vector<int>> res;
        for(auto p : m){
            res.push_back(p.second);
        }
        return res;
    }
};
