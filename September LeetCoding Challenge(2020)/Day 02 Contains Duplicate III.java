class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        TreeSet<Long> tree = new TreeSet();
        for(int i=0; i<nums.length; i++){
            // the try catch here is not necessary
            try{
                Long floor = tree.floor((long) nums[i]);
                if(floor != null && nums[i] - floor <= t) return true;
                Long ceil = tree.ceiling((long) nums[i]);
                if(ceil != null && ceil - nums[i] <= t) return true;
            }catch(NullPointerException e){}
            
            
            tree.add((long) nums[i]);
            if(tree.size() > k){
                tree.remove((long)nums[i - k]);
            }
        }
        return false;
    }
}
