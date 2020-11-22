class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] dict = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        HashSet<String> s = new HashSet<>();
        for(int i=0; i<words.length; i++){
            String temp = "";
            String cur = words[i];
            for(int j=0; j<words[i].length(); j++){
                temp += dict[cur.charAt(j) - 'a'];
            }
            s.add(temp);
        }
        return s.size();
    }
}
