/*
Greedy solution,

we always put the cam on the parent of the leaf node, because this will cover the 2 child, self and parent

*/
class Solution {
    int res = 0;
    public enum state{ HAS_CAM, COVERED, NEED_COVER};
    
    public int minCameraCover(TreeNode root) {
        state result = cover(root);
        if (result == state.NEED_COVER) res++;
        return res;
    }
    
    public state cover(TreeNode node){
        if (node == null) return state.COVERED;
        
        state left = cover(node.left);
        state right = cover(node.right);
        
        if (left == state.NEED_COVER || right == state.NEED_COVER){
            res++;
            return state.HAS_CAM;
        }
        
        if (left == state.HAS_CAM || right == state.HAS_CAM){
            return state.COVERED;
        }
        return state.NEED_COVER;
    }
}
