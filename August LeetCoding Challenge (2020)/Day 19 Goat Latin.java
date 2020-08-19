class Solution {
    public String toGoatLatin(String S) {
        String res = "";
        String a = "a";
        String words[] = S.split(" ");
        if(words.length == 0) return S;
        
        for(int i=0; i<words.length; i++){
            String word = words[i];
            if(isVowel(word.charAt(0))){
                word += "ma";
            }else{
                word += word.charAt(0) + "ma";
                word = word.substring(1);
            }
            word += a;
            a += "a";
            res += word + " ";
        }
        return res.trim();
    }
    public boolean isVowel(char c){
        c = Character.toLowerCase(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}
