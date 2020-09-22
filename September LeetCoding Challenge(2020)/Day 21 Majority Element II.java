// Boyer-Moore Voting Algorithm
class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int n = nums.length;
        ArrayList<Integer> res = new ArrayList();
        if (n == 0) return res;
        Integer me1 = null, me2 = null;
        int count1 = 0, count2 = 0;
        for(int x : nums){
            if (me1 != null && me1 == x){
                count1++;
            }else if (me2 != null && me2 == x){
                count2++;
            }else if (count1 == 0){
                me1 = x;
                count1 = 1;
            }else if (count2 == 0){
                me2 = x;
                count2 = 1;
            }else{
                count1--;
                count2--;
            }
        }
    
        count1 = 0;
        count2 = 0;
        for(int x:nums){
            if(me1 != null && x == me1) count1++;
            if(me2 != null && x == me2) count2++;
        }
        if(count1 > n/3) res.add(me1);
        if(count2 > n/3) res.add(me2);
        return res;
    }
}
