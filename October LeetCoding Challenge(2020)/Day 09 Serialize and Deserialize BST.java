/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        dfs(root, sb);
        return sb.toString();
    }
    public void dfs(TreeNode node, StringBuilder sb){ // preorder
        if (node == null) return;
        sb.append(node.val + " ");
        dfs(node.left, sb);
        dfs(node.right, sb);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String arr[] = data.split(" ");
        TreeNode root = null;
        for(String x : arr){
            if (x.length() > 0){
                root = build(root, Integer.parseInt(x));
            }
        }
        return root;
    }
    public static TreeNode build(TreeNode node, int val){
        if (node == null) return new TreeNode(val);
        if (val < node.val){
            node.left = build(node.left, val);
        }else{
            node.right = build(node.right, val);
        }
        return node;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// String tree = ser.serialize(root);
// TreeNode ans = deser.deserialize(tree);
// return ans;
