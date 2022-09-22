class Solution {
        public String reverseWords(String s) {
        String[] temp = s.split(" ");
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < temp.length; i++) {
            result.append(new StringBuffer(temp[i]).reverse()).append(" ");
        }
        return result.toString().trim();
    
    }
}
