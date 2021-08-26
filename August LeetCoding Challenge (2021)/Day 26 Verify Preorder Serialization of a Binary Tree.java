class Solution {
    public boolean isValidSerialization(String preorder) {
        String[] arr = preorder.split(",");
        int bal = 1; // bal = out degree - in degree
        // if encounter a not null node, we -1 (from parent), and +2 (for 2 child)
        // if in any steps the value < 0, then it's invalid
        // at the last, we check if the value == 0
        for(String node : arr){
            if (--bal < 0) return false;
            if (!node.equals("#")){
                bal += 2;
            }
        }
        return bal == 0;
    }
}
