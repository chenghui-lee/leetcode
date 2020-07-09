class Solution {
    int max_width;
    HashMap<Integer, Integer> left; // only for storing the leftmost index for each depth
    public int widthOfBinaryTree(TreeNode root) {
        max_width = 0;
        left = new HashMap();
        dfs(root, 0, 0);
        return max_width;
    }
    
    public void dfs(TreeNode node, int depth, int index){
        if (node == null) return;
        left.computeIfAbsent(depth, i->index); // only put the leftmost node's index. i->index is a lambda function
        max_width = Math.max(max_width, 1 + index - left.get(depth));
        dfs(node.left, depth+1, 2*index);
        dfs(node.right, depth+1, 2*index+1);
    }
}
