class Solution {
    int res = 0;
    public enum state{ HAS_CAM, COVERED, NEED_COVER};
    
    public int minCameraCover(TreeNode root) {
        return cover(root) == state.NEED_COVER? res+1 : res;    
    }
    
    public state cover(TreeNode node){
        if (node == null) return state.COVERED;
        
        state left = cover(node.left);
        state right = cover(node.right);
        
        // if any child node needs cover, we need to place a cam at here
        if (left == state.NEED_COVER || right == state.NEED_COVER){
            res++;
            return state.HAS_CAM;
        }
        
        // if any of the child has cam, we are covered
        if (left == state.HAS_CAM || right == state.HAS_CAM){
            return state.COVERED;
        }
        // else we need cover
        return state.NEED_COVER;
    }
}
