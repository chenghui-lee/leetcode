class Solution {
public:
    vector<int> l;
    int count = 0;
    
    void dfs(TreeNode* node, int sum){
        if(!node) return;
        l.push_back(node->val);  
        int temp = 0;
        for(int i=l.size()-1; i>=0; i--){
            temp += l[i];
            if(temp == sum) count++;
        }
        dfs(node->left, sum);
        dfs(node->right, sum);
        l.pop_back();
    }
    
    int pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return count;
    }
    
};
