class Solution {
    public String reverseWords(String s) {
        s = s.trim();
        String[] rev = s.split(" ");
        
        StringBuilder res = new StringBuilder();
        
        for(int i=rev.length-1; i>0; i--){
            if (!rev[i].trim().equals("")){
                res.append(rev[i]);
                res.append(" ");
            }
        }
        res.append(rev[0]);
        return res.toString();
        
    }
}
