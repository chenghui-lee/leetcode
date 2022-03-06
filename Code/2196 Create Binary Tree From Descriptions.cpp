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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> m;
        unordered_map<int, bool> hasParent;
        
        unordered_set<int> s;
        for(auto x : descriptions){
            int cur = x[0], child = x[1];
            bool isLeft = x[2];
            
            s.insert(cur);
            // create if not exist
            TreeNode* c = new TreeNode(cur);
            TreeNode* cld = new TreeNode(child);
            if (m.find(cur) != m.end()) c = m[cur];
            if (m.find(child) != m.end()) cld = m[child];
            
            // do the linking
            if (isLeft) c->left = cld;
            else c->right = cld;
            
            // replace back in map
            m[cur] = c;
            m[child] = cld;
            
            
            hasParent[child] = true;
        }
        for(int x : s){
            if (hasParent.find(x) == hasParent.end()) return m[x];
        }
        return NULL;
        
    }
};
