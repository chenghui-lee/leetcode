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

/*
1) declare hasX and hasY to check if x and y appear on that depth
2) check the current node's child node, if they are x and y, they are siblings (false)
3) after scanning for the entire depth, if both hasX and hasY is true, return true
4) if after scanning for entire depth, only either 1 is true, return false
5) if finish all the nodes, return false;


*/


class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        if (root == NULL){
            return false;
        }
        q.push(root);
        while (!q.empty()){
            bool hasX = false;
            bool hasY = false;
            int numOfNodes = q.size();
            for (int i = 0; i<numOfNodes; i++){
                TreeNode* currentNode = q.front(); q.pop();
                
                // check the currentNode 

                if (currentNode->val == x){
                    hasX = true;
                }else if (currentNode->val == y){
                    hasY = true;
                }
                
                // check if is siblings (same parent)
                
                if (currentNode->left && currentNode->right) {
                    if (currentNode->left->val == x && currentNode->right->val == y) {
                        return false;
                    }
                    if (currentNode->right->val == x && currentNode->left->val == y) {
                        return false;
                    }
                }
                if (currentNode->left){
                    q.push(currentNode->left);
                }
                if (currentNode->right){
                    q.push(currentNode->right);
                }
                    
            }
            if(hasX && hasY){
                return true;
            }
            if (hasX || hasY){
                return false;
            }
        }
        return false;
    }
};

// another solution using dfs
vector<int> dfs(TreeNode* root,int target,int depth,int parent)
    {
        if(root==NULL)
            return {};
        
        if(root->val==target)
        {
            return {depth,parent};
        }
        else
        {
            parent = root->val;
            vector<int> l = dfs(root->left,target,depth+1,parent);
            vector<int> r = dfs(root->right,target,depth+1,parent);
            
            if(l.empty())
                return r;
            else
                return l;
        }
        
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int> d1 = dfs(root,x,0,-1);
        vector<int> d2 = dfs(root,y,0,-1);
        // cout<<d1[1]<<" "<<d2[1]<<endl;
        if(d1[0]==d2[0] && (d1[1]!=d2[1]))
            return true;
        else
            return false;
    }
