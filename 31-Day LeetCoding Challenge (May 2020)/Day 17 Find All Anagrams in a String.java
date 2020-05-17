// https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/636967/java-detailed-explanation-w-code-w-diagrams-on-time-single-array/
// Sliding windows technique
class Solution {
     public List<Integer> findAnagrams(String s, String p) {
        int m = s.length(), n = p.length();
        if(n > m) return new ArrayList<>();
        
        int[] dict = new int[26];
        for(int i = 0; i < n; i++){
            dict[p.charAt(i) - 'a']--;
            dict[s.charAt(i) - 'a']++;
        }
        
        List<Integer> result = new ArrayList<>();
        for(int i = n; i < m; i++){
            if(areAllZeroes(dict)){
                list.add(i - n);
            }
            dict[s.charAt(i) - 'a']++;
            dict[s.charAt(i - n) - 'a']--;
        }
        if(areAllZeroes(dict)){
            result.add(m - n);
        }
        
        return result;
    }
    
    boolean areAllZeroes(int[] array){
        for(int i = 0; i < array.length; i++){
            if(array[i] != 0) return false;
        }
        return true;
    }
}
