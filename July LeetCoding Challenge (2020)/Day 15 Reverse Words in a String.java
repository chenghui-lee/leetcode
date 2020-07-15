class Solution {
    public String reverseWords(String s) {
        s = s.trim();
        System.out.println(s);
        String[] words = s.split(" ");
        String ans = "";
        for(int i=words.length-1; i>=0; i--){
            ans += words[i] + " ";
        }
        String ans2 = "";
        int spacecount = 0;
        for (int i=0; i<ans.length(); i++){
            if (spacecount == 1) ans2 += " ";
            if (ans.charAt(i) == ' '){
                spacecount ++;
                continue;
            }
            ans2 += ans.charAt(i);
            spacecount = 0;
            
        }
        return ans2;
    }
}
