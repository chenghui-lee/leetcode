class Solution {
    public int lengthOfLastWord(String s) {
        s = s.trim();
        String[] arr = s.split(" ");
        
        for(int i=arr.length -1 ; i>=0 ;i++){
            if(arr[i].equals(" ")) continue;
            else return arr[i].length();
        }
        return 0;
    }
}
