// https://leetcode.com/problems/maximum-width-of-binary-tree/discuss/232952/C%2B%2B-BFS-fix-overflow-problem
// @ lubenets
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int max_width = 0;
        while(q.size()){
            int size = q.size();
            int offset = q.front().second;
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
