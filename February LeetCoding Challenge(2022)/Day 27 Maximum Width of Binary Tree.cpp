/*
Idea is to use the node index,
where left = idx*2
right = idx*2 + 1

One thing to note is that the value can be very large, 
so we need to use 'offset' to change the range (ans still still be the same, since we minus a constant factor)

*/
class Solution {
public:
int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, long>> q;
        q.push({root, 0});
    
        long max_width = 0;
        while(q.size()){
            int size = q.size();
            long offset = q.front().second; // changed from int to long for the latest test cases
            max_width = max(max_width, q.back().second - q.front().second + 1);
            
            for(int i = 0; i < size; i++){
                auto node = q.front(); q.pop();
                if(node.first->left)
                    q.push({node.first->left, 2*(node.second - offset)});
                if(node.first->right)
                    q.push({node.first->right, 2*(node.second - offset) + 1});
            }
        }
        return max_width;
    }
};
